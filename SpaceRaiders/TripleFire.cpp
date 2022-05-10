#include "stdafx.h"
#include "TripleFire.h"

#include "PlayerShip.h"

void TripleFire::Activate(PlayerShip* player)
{
    PowerUp::Activate(player);
    player->Fire(Vector2D{0.5f,-0.5f});
    player->Fire(Vector2D{0.0f,-1.0f});
    player->Fire(Vector2D{-0.5f,-0.5f});
}
