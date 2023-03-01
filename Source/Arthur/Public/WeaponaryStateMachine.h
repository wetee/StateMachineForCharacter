// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "State.h"

#include "WeaponaryStateMachine.generated.h"

class IState;
class UStateOnHand;
class UStateSword;
class UInputComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARTHUR_API UWeaponaryStateMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponaryStateMachine();

private:
	IState* currentState;
	IState* previousState;
	
	IState* onHand;
	IState* sword;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;

	void SetState(IState* newState);
	

	void InitializeMachine();
	void EnterMachine();
	void ExitMachine();

	void BindInputComponent(UInputComponent* inputComponent);
	void UnbindInputComponent(UInputComponent* inputComponent);

	IState* GetCurrentState() const {return currentState;}
	IState* GetPreviousState() const {return previousState;}
	IState* GetOnHandState() const {return onHand;}
	IState* GetSwordState() const {return sword;}
	

};
