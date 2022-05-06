#include "stdafx.h"
#include "PlayField.h"

PlayField* PlayField::GetInstance()
{
    if(instance_ == nullptr)
        instance_ = new PlayField;

    return instance_;
}

PlayField* PlayField::instance_ = nullptr;
