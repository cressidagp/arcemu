/*
 * Moon++ Scripts for Ascent MMORPG Server
 * Copyright (C) 2007-2008 Moon++ Team <http://www.moonplusplus.info/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Setup.h"

#define ITEM_ELEMENTAL_SAPTA 27317

class SeerSkaltesh_Gossip : public Arcemu::Gossip::Script
{
	public:
		void OnHello( Object* pObject, Player* plr )
		{
			Arcemu::Gossip::Menu::SendQuickMenu( pObject->GetGUID(), 9622, plr, 1, Arcemu::Gossip::ICON_CHAT, "Show me, Seer." );
		}

		void OnSelectOption( Object* pObject, Player* plr, uint32 Id, const char* Code )
		{
			if( !pObject->IsCreature() )
				return;
				
			if( plr->GetItemInterface()->GetItemCount( ITEM_ELEMENTAL_SAPTA, false ) == 0 )
			{
				plr->GetItemInterface()->AddItemById( ITEM_ELEMENTAL_SAPTA, 1, 0 );
			}
				
			Arcemu::Gossip::Menu::SendSimpleMenu( pObject->GetGUID(), 9623, plr );
		}

		void Destroy() { delete this; }
};

void SetupTheExodarGossip( ScriptMgr* mgr )
{
	mgr->register_creature_gossip( 18985, new SeerSkaltesh_Gossip );
}
