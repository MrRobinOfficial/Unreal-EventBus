![Banner](Resources/Banner.png)

<div align="center">
  
[![license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/mrrobinofficial/unreal-eventbus/blob/HEAD/LICENSE.txt)
![plugin-status](https://img.shields.io/badge/plugin_status-ready_to_use-green)
![maintenance-status](https://img.shields.io/badge/maintenance-passively--maintained-yellowgreen.svg)

</div>

## ⚙️ Supported Versions

This plug-in was last built against Windows, Unreal Engine 5.4+.

However, this code should work on other Unreal Engine versions.

## ⚒️ Installation

You can install from the [release section](https://github.com/MrRobinOfficial/Unreal-EventBus/releases/latest).

Alternatively, you can install this plugin via terminal with [*git*](https://git-scm.com/).

_Here is the command for installing it_:

```console
git clone git@github.com:MrRobinOfficial/Unreal-EventBus.git EventBus
```

## 📝 Quick guide

This plugin features a subsystem named `UEventSubsystem`, which enables you to register and invoke events. The event subsystem maintains a dictionary of events and their corresponding callbacks. These callbacks are stored in a list, allowing multiple callbacks to be registered for the same event. This design promotes a modular and maintainable approach to event-based systems.

The subsystem supports two types of invocation: `UEventSubsystem::Invoke()` and `UEventSubsystem::InvokeWithPayload()`. The payload is a `UObject` pointer that can be used to pass data between callbacks.

Inside that class, there a couple of functions that you can use.

### Getting the event subsystem

```cpp
#include "EventSubsystem.h"

UGameInstance* GameInstance = ...;
auto* EventSubsystem = GameInstance->GetSubsystem<UEventSubsystem>();
```

### Registering events

```cpp
UEventSubsystem* EventSubsystem = ...;

FOnEventSignature Delegate;
Delegate.BindUObject(this, &UEventSubsystem::OnPlayerDied);
EventSubsystem->RegisterEvent(TEXT("player_died"), Delegate);

// Callback will be invoked when `player_died` event is invoked
UFUNCTION()
void OnPlayerDied(UObject* Payload) { }
```

### Unregistering events

#### With specific callback

```cpp
UEventSubsystem* EventSubsystem = ...;

FOnEventSignature Delegate;
Delegate.BindUObject(this, &UEventSubsystem::OnPlayerDied);
EventSubsystem->UnregisterEvent(TEXT("player_died"), Delegate);

// Callback will be invoked when `player_died` event is invoked
UFUNCTION()
void OnPlayerDied(UObject* Payload) { }
```

#### Unregistering all events

```cpp
UEventSubsystem* EventSubsystem = ...;
EventSubsystem->UnregisterAllEvents(TEXT("player_died"));
```

### Invoking events

#### With payload

```cpp
UObject* Payload = ...;
EventSubsystem->InvokeWithPayload(TEXT("player_died"), Payload);
```

#### Without payload

```cpp
EventSubsystem->InvokeWithPayload(TEXT("player_died"));
```

## 🆘 Support
If you have any questions or issue, just write either to my [YouTube channel](https://www.youtube.com/@mrrobinofficial), [Email](mailto:mrrobin123mail@gmail.com) or [Twitter DM](https://twitter.com/MrRobinOfficial).
