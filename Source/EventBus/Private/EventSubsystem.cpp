// Copyright 2024-2025 MrRobin. All Rights Reserved.

#include "EventSubsystem.h"

void UEventSubsystem::RegisterEvent(FName Name, FOnEventSignature Callback)
{
	if (Events.Contains(Name))
	{
		// Add the callback to the existing list
		FEventCollection& Collection = Events[Name];
		Collection.Callbacks.Add(Callback);
		return;
	}

	// Create a new list and add the callback
	Events.Add(Name, FEventCollection { Callback });
}

void UEventSubsystem::UnregisterEvent(FName Name, FOnEventSignature Callback)
{
	if (!Events.Contains(Name))
		return;

	FEventCollection& Collection = Events[Name];
	Collection.Callbacks.Remove(Callback);
}

void UEventSubsystem::UnregisterAllEvents(FName Name)
{
	if (!Events.Contains(Name))
		return;

	FEventCollection& Collection = Events[Name];
	Collection.Callbacks.Reset();
}

void UEventSubsystem::Invoke(FName Name)
{
	if (!Events.Contains(Name))
		return;

	const FEventCollection& Collection = Events[Name];

	for (const FOnEventSignature& Callback : Collection.Callbacks)
		Callback.ExecuteIfBound(nullptr);
}

void UEventSubsystem::InvokeWithPayload(FName Name, UObject* Payload)
{
	if (!Events.Contains(Name))
		return;

	const FEventCollection& Collection = Events[Name];

	for (const FOnEventSignature& Callback : Collection.Callbacks)
		Callback.ExecuteIfBound(Payload);
}