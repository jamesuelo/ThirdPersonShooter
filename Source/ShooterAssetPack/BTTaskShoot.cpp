// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskShoot.h"
#include "AIController.h"
#include "ShooterCharacter.h"

UBTTaskShoot::UBTTaskShoot() {
	NodeName = "Shoot";
}


EBTNodeResult::Type UBTTaskShoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr){
		return EBTNodeResult::Failed;
	}
	AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (Character == nullptr) {
		return EBTNodeResult::Failed;
	}
	
	Character->Shoot();
	return EBTNodeResult::Succeeded;
}

