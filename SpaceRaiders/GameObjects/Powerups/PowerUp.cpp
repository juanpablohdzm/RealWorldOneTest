#include "stdafx.h"
#include "PowerUp.h"

#include "../Player/PlayerShip.h"

#include "../../GameManager.h"
#include "../../PlayField.h"

void PowerUp::Update()
{

    if(!isActive_)
    {
        Move({0.0f,1.0f});
    
        auto player = GameManager::GetInstance()->GetPlayerObject();

        if (pos_.y() > PlayField::GetInstance()->GetBounds().y())
        {
            Destroy();
            return;
        }

        if(pos_ == player->GetPosition())
        {
            auto ptr = dynamic_cast<PlayerShip*>(player.get());
            Activate(ptr);
        }
    }
    else
    {
        auto currentTime  = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = currentTime - activateTime_;
        
        if(elapsed_seconds.count() >= duration_)
        {
            Destroy();
        }
    }
}

void PowerUp::Destroy()
{
    GameManager::GetInstance()->RemoveObject(this);
}


void PowerUp::Activate(PlayerShip* player)
{
    activateTime_  = std::chrono::system_clock::now();
    pos_ = Vector2D(100,100);
    player_ = player;
    isActive_ = true;
}
