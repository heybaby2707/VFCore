/*
 * Copyright (C) 2011-2014 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2014 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __BATTLEGROUNDBE_H
#define __BATTLEGROUNDBE_H

#include "Battleground.h"

enum BattlegroundBEObjectTypes
{
    BG_BE_OBJECT_DOOR_1         = 0,
    BG_BE_OBJECT_DOOR_2         = 1,
    BG_BE_OBJECT_DOOR_3         = 2,
    BG_BE_OBJECT_DOOR_4         = 3,
    BG_BE_OBJECT_BUFF_1         = 4,
    BG_BE_OBJECT_BUFF_2         = 5,
    BG_BE_OBJECT_MAX            = 6
};

enum BattlegroundBEObjects
{
    BG_BE_OBJECT_TYPE_DOOR_1    = 183971,
    BG_BE_OBJECT_TYPE_DOOR_2    = 183973,
    BG_BE_OBJECT_TYPE_DOOR_3    = 183970,
    BG_BE_OBJECT_TYPE_DOOR_4    = 183972,
    BG_BE_OBJECT_TYPE_BUFF_1    = 184663,
    BG_BE_OBJECT_TYPE_BUFF_2    = 184664
};

class BattlegroundBE : public Battleground
{
    public:
        BattlegroundBE();
        ~BattlegroundBE();

        /* inherited from BattlegroundClass */
        void AddPlayer(Player* player);
        void StartingEventCloseDoors();
        void StartingEventOpenDoors();

        void RemovePlayer(Player* player, uint64 guid, uint32 team);
        void HandleAreaTrigger(Player* Source, uint32 Trigger);
        bool SetupBattleground();
        void Reset();
        void FillInitialWorldStates(WorldStateBuilder& builder);
        void HandleKillPlayer(Player* player, Player* killer);

        /* Scorekeeping */
        void UpdatePlayerScore(Player* Source, uint32 type, uint32 value, bool doAddHonor = true);
};
#endif
