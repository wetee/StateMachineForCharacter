#include "StateOnHand.h"


UStateOnHand::UStateOnHand(){
	PrimaryComponentTick.bCanEverTick = true;

}

void UStateOnHand::BeginPlay(){
	Super::BeginPlay();
}

void UStateOnHand::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UStateOnHand::SetStateMachine(UWeaponaryStateMachine* newStateMachine) {
	weaponaryStateMachine = newStateMachine;
}

void UStateOnHand::EnterState() {
	UE_LOG(LogTemp, Warning, TEXT("Entered ON HAND state"))
}

void UStateOnHand::ExitState() {
	UE_LOG(LogTemp, Warning, TEXT("Exited ON HAND state"))
}

void UStateOnHand::BindInputComponent(UInputComponent* inputComponent) {
	UE_LOG(LogTemp, Warning, TEXT("Binded grab ON HAND STATE"))
	inputComponent->BindAction(FName("Grab"), IE_Pressed, this, &UStateOnHand::Grab);
}

void UStateOnHand::UnbindInputComponent(UInputComponent* inputComponent) {
	UE_LOG(LogTemp, Warning, TEXT("Unbinded grab ON HAND STATE"))
	inputComponent->RemoveActionBinding(FName("Grab"), IE_Pressed);
}

FString UStateOnHand::ToString() {
	return FString("On Hand State");	
}

void UStateOnHand::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("grabbed"))
}










