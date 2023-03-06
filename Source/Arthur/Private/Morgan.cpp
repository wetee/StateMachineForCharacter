#include "Morgan.h"

#include "StateOnHand.h"
#include "StateSword.h"
#include "WeaponaryStateMachine.h"

AMorgan::AMorgan()
{
	PrimaryActorTick.bCanEverTick = true;
	
	weaponaryStateMachine = CreateDefaultSubobject<UWeaponaryStateMachine>(TEXT("Weaponary"));
	
	stateOnHand = CreateDefaultSubobject<UStateOnHand>(TEXT("On Hand"));
	StateSword = CreateDefaultSubobject<UStateSword>(TEXT("Sword"));

	weaponaryStateMachine->InitializeMachine();	
}

void AMorgan::BeginPlay()
{
	Super::BeginPlay();
}

void AMorgan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMorgan::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	weaponaryStateMachine->BindInputComponent(PlayerInputComponent);
	
	playerInputComponent = PlayerInputComponent;
	playerInputComponent->BindAction(FName("OnHand") ,IE_Pressed, this, &AMorgan::chooseOnHand);
	playerInputComponent->BindAction(FName("Sword"),IE_Pressed, this, &AMorgan::chooseSword);
}

void AMorgan::chooseOnHand() {
	weaponaryStateMachine->SetState(weaponaryStateMachine->GetOnHandState());
}

void AMorgan::chooseSword() {
	weaponaryStateMachine->SetState(weaponaryStateMachine->GetSwordState());
}




