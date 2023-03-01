
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "State.generated.h"

class UWeaponaryStateMachine;
class UInputComponent;

UINTERFACE(MinimalAPI)
class UState : public UInterface
{
	GENERATED_BODY()
};

class ARTHUR_API IState
{
	GENERATED_BODY()

private:
	IState* baseState;
public:
	virtual void SetStateMachine(UWeaponaryStateMachine* weaponaryStateMachine) = 0;
	
	virtual void EnterState() = 0;
	virtual void ExitState() = 0;

	virtual void BindInputComponent(UInputComponent* inputComponent) = 0;
	virtual void UnbindInputComponent(UInputComponent* inputComponent) = 0;

	virtual FString ToString() = 0;

	IState* GetBaseState() const {return baseState;}
	void SetBaseState(IState* newState) {baseState = newState;}
	

};
