#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "Components/ActorComponent.h"
#include "StateSword.generated.h"

class UWeaponaryStateMachine;
class UInputComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARTHUR_API UStateSword : public UActorComponent, public IState
{
	GENERATED_BODY()

public:	
	UStateSword();
private:
	UWeaponaryStateMachine* weaponaryStateMachine;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void SetStateMachine(UWeaponaryStateMachine* weaponaryStateMachine) override;
	
	virtual void EnterState() override;
	virtual void ExitState() override;

	virtual void BindInputComponent(UInputComponent* inputComponent) override;
	virtual void UnbindInputComponent(UInputComponent* inputComponent) override;

	virtual FString ToString() override;
		
};
