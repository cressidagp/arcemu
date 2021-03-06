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

class Hilary_Gossip : public Arcemu::Gossip::Script
{
	public:
		void OnHello( Object* pObject, Player* plr )
		{
			Arcemu::Gossip::Menu menu( pObject->GetGUID(), 0 );
			
			if( plr->HasFinishedQuest( 3741 ) == true )
			{
				menu.setTextID( 2274 );
			}
			else
			{
				menu.setTextID( 2273 );
				sQuestMgr.FillQuestMenu( TO< Creature* >( pObject ), plr, menu );
			}
			
			menu.Send( plr );
		}

		void Destroy() { delete this; }
};

class Shawn_Gossip : public Arcemu::Gossip::Script
{
	public:
		void OnHello( Object* pObject, Player* plr )
		{
			Arcemu::Gossip::Menu menu( pObject->GetGUID(), 0 );
			
			if(plr->HasFinishedQuest( 3741 ) == true )
			{
				menu.setTextID( 2277 );
			}
			else
			{
				menu.setTextID( 2276 );
				sQuestMgr.FillQuestMenu( TO< Creature* >( pObject ), plr, menu );
			}
			
			menu.Send( plr );
		}

		void Destroy() { delete this; }
};

void SetupRedridgeMountainsGossip( ScriptMgr* mgr )
{
	mgr->register_creature_gossip( 8962, new Hilary_Gossip );
	mgr->register_creature_gossip( 8965, new Shawn_Gossip );
}
