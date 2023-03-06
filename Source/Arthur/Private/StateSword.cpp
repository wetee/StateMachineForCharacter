#include "StateSword.h"

UStateSword::UStateSword()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UStateSword::BeginPlay()
{
	Super::BeginPlay();
}

void UStateSword::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStateSword::SetStateMachine(UWeaponaryStateMachine* newStateMachine) {
	weaponaryStateMachine = newStateMachine;
}

void UStateSword::EnterState() {
	UE_LOG(LogTemp, Warning, TEXT("Entered SWORD state"))
}

void UStateSword::ExitState() {
	UE_LOG(LogTemp, Warning, TEXT("Exited SWORD state"))
}

void UStateSword::BindInputComponent(UInputComponent* inputComponent) {
	UE_LOG(LogTemp, Warning, TEXT("Binded swing SWORD STATE"))
	inputComponent->BindAction(FName("Swing"), IE_Pressed, this, &UStateSword::Swing);
}

void UStateSword::UnbindInputComponent(UInputComponent* inputComponent) {
	UE_LOG(LogTemp, Warning, TEXT("Unbinded swing SWORD STATE"))
	inputComponent->RemoveActionBinding(FName("Swing"), IE_Pressed);
}

FString UStateSword::ToString() {
	return FString("Sword State");	
}

void UStateSword::Swing() {
	UE_LOG(LogTemp, Warning, TEXT("Swinged"))
	
}



