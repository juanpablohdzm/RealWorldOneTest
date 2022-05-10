#include "stdafx.h"
#include "FireRateBoost.h"

#include "PlayerShip.h"

void FireRateBoost::Activate(PlayerShip* player)
{
    PowerUp::Activate(player);
    player->SetFireRate(1.0f);
}

void FireRateBoost::Destroy()
{
    PowerUp::Destroy();
    if(player_ && isActive_)
    {
        player_->SetFireRate(2.0f);
    }
}
