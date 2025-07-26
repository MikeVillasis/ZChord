// Copyright Epic Games, Inc. All Rights Reserved.


#include "ZChordPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "ZChordCameraManager.h"

AZChordPlayerController::AZChordPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AZChordCameraManager::StaticClass();
}

void AZChordPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
