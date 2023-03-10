#include "WeaponaryStateMachine.h"

#include "StateOnHand.h"
#include "StateSword.h"
#include "Components/InputComponent.h"


UWeaponaryStateMachine::UWeaponaryStateMachine()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UWeaponaryStateMachine::BeginPlay()
{
	Super::BeginPlay();
}

void UWeaponaryStateMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UWeaponaryStateMachine::SetState(IState* newState) {
	if(currentState == newState){
		UE_LOG(LogTemp, Warning, TEXT("Weaponary: You have already chose"));
		return;
	}
	currentState->UnbindInputComponent(playerInputComponentWSM);
	currentState->ExitState();

	previousState = currentState;
	currentState = newState;
	
	currentState->EnterState();
	currentState->BindInputComponent(playerInputComponentWSM);
}


void UWeaponaryStateMachine::InitializeMachine() {
	onHand = Cast<IState>(GetOwner()->FindComponentByClass<UStateOnHand>());
	sword =Cast<IState>(GetOwner()->FindComponentByClass<UStateSword>());

	currentState = onHand;
	
	SetState(onHand);
	
}

void UWeaponaryStateMachine::EnterMachine() {
	currentState->EnterState();
}

void UWeaponaryStateMachine::ExitMachine() {
	currentState->ExitState();
}


void UWeaponaryStateMachine::BindInputComponent(UInputComponent* inputComponent) {
	if (!inputComponent){
		UE_LOG(LogTemp, Error, TEXT("HandActionStateMachine: InputComponent is null"));
	}
	else{
		playerInputComponentWSM = inputComponent;
	}
	currentState->BindInputComponent(inputComponent);
}

void UWeaponaryStateMachine::UnbindInputComponent(UInputComponent* inputComponent) {
	currentState->UnbindInputComponent(inputComponent);
}






