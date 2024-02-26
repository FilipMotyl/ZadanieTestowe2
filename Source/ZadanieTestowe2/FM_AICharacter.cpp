#include "FM_AICharacter.h"
#include "FM_Ball.h"

void AFM_AICharacter::DropBall()
{
	if (BallCount <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no balls. Sorry."), *GetName());
	}
	else
	{
		AFM_Ball* BallPtr = GetWorld()->SpawnActor<AFM_Ball>(BallClass, SpawnPoint->GetComponentLocation(), GetActorRotation());
		if (--BallCount == 0)
		{
			HeldBallMesh->SetVisibility(false);
		}
	}
}