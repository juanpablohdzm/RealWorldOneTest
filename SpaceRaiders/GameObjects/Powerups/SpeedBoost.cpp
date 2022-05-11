#include "stdafx.h"
#include "SpeedBoost.h"

#include "../Player/PlayerShip.h"

void SpeedBoost::Activate(PlayerShip* player)
{
    PowerUp::Activate(player);
    player->SetSpeed(2.0f);
}

void SpeedBoost::Destroy()
{
    PowerUp::Destroy();
    if(player_ && isActive_)
    {
        player_->SetSpeed(1.0);
    }
}


