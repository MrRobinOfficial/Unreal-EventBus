// Copyright 2024-2025 MrRobin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EventSubsystem.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnEventSignature, UObject*, Payload);

USTRUCT()
struct FEventCollection
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FOnEventSignature> Callbacks;

public:
	FEventCollection()
		: Callbacks()
	{ }

	FEventCollection(FOnEventSignature Callback)
		: Callbacks({ Callback })
	{ }
};

/// <summary>
/// An event bus subsystem.
/// <para>
/// The Event Bus System facilitates event-based communication within the game.
/// It helps in reducing dependencies and preventing spaghetti code, enabling a more modular and maintainable architecture.
/// </para>
/// </summary>
UCLASS(Blueprintable)
class EVENTBUS_API UEventSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FName, FEventCollection> Events;

public:
	/// <summary>
	/// Registers an event
	/// </summary>
	/// <param name="Name">The name of the event</param>
	/// <param name="Callback">A callback</param>
	UFUNCTION(BlueprintCallable, Category = "Plugins|Event Bus")
	void RegisterEvent(FName Name, FOnEventSignature Callback);

	/// <summary>
	/// Unregisters an event
	/// </summary>
	/// <param name="Name">The name of the event</param>
	/// <param name="Callback">A callback</param>
	UFUNCTION(BlueprintCallable, Category = "Plugins|Event Bus")
	void UnregisterEvent(FName Name, FOnEventSignature Callback);

	/// <summary>
	/// Unregisters all events
	/// </summary>
	/// <param name="Name">The name of the event</param>
	UFUNCTION(BlueprintCallable, Category = "Plugins|Event Bus")
	void UnregisterAllEvents(FName Name);

	/// <summary>
	/// Invokes an event
	/// </summary>
	/// <param name="Name">The name of the event</param>
	UFUNCTION(BlueprintCallable, Category = "Plugins|Event Bus")
	void Invoke(FName Name);

	/// <summary>
	/// Invokes an event with a custom payload
	/// </summary>
	/// <param name="Name">The name of the event</param>
	/// <param name="Payload">Custom payload</param>
	UFUNCTION(BlueprintCallable, Category = "Plugins|Event Bus")
	void InvokeWithPayload(FName Name, UObject* Payload);
};