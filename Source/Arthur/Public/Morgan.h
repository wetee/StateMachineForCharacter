// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Morgan.generated.h"

class UWeaponaryStateMachine;
class UStateOnHand;
class UStateSword;
class UCameraComponent;
class USpringArmComponent;
class UInputComponent;

UCLASS()
class ARTHUR_API AMorgan : public ACharacter {
	GENERATED_BODY()

public:
	AMorgan();

private:
	UInputComponent* playerInputComponent;
	UWeaponaryStateMachine* weaponaryStateMachine;
	
	UStateOnHand* stateOnHand;
	UStateSword* StateSword;
	
protected:
	virtual void BeginPlay() override;

	void chooseOnHand();
	void chooseSword();

	
public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent( UInputComponent* PlayerInputComponent) override;
	UStateOnHand* GetOnHandStateComponent() const{return stateOnHand;}
	UStateSword* GetSwordStateComponent() const{return StateSword;}

};
