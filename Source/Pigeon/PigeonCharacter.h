// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PigeonCharacter.generated.h"

UCLASS(config=Game)
class APigeonCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	APigeonCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	
	UPROPERTY(EditAnywhere, Category=Camera)
	bool FreeLookStatus;

	UPROPERTY(EditAnywhere)
	bool GrenadeStatus;

	UPROPERTY(EditAnywhere)
	bool FlashLightStatus;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
	
	void ToggleFreeLookStatus();

	void ToggleGrenadeStatus();
	
	void ToggleFlashlightStatus();

	UFUNCTION(BlueprintCallable)
	void DrawLineInWorld(FVector From, FVector To, float Lifetime = 1.0f, FLinearColor Color = FLinearColor::Red, float Thickness = .0f);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayerFire();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void TargetHit(AActor* Actor, float Damage = 30, FVector ImpactNormal = FVector(.0f, .0f, .0f));

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void LaunchGrenade();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool GetGrenadeStatus() const { return GrenadeStatus; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool GetFlashlightStatus() const { return FlashLightStatus; }

	UFUNCTION(BlueprintCallable)
	void SetFlashlightStatus(const bool Status) { FlashLightStatus = Status; }
};
