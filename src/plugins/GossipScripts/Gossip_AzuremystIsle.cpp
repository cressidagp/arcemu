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

class Proenitus_Gossip : public Arcemu::Gossip::Script
{
	public:
		void OnHello( Object* pObject, Player* plr )
		{
			Arcemu::Gossip::Menu menu( pObject->GetGUID(), 0 );
			
			if(plr->HasFinishedQuest( 9280 ) == true )
			{
				menu.setTextID( 8669 );
			}
			else
			{
				menu.setTextID( 8667 );
			}
			
			sQuestMgr.FillQuestMenu( TO< Creature* >( pObject ), plr, menu );
			menu.Send( plr );
		}

		void Destroy() { delete this; }
};

class BotanistTaerix_Gossip : public Arcemu::Gossip::Script
{
	public:
		void OnHello( Object* pObject, Player* plr )
		{
			Arcemu::Gossip::Menu menu( pObject->GetGUID(), 0 );
			
			if(plr->HasFinishedQuest( 9293 ) == true )
			{
				menu.setTextID( 8666 );
			}
			else
			{
				menu.setTextID( 8664 );
			}
			
			sQuestMgr.FillQuestMenu( TO< Creature* >( pObject ), plr, menu );
			menu.Send( plr );
		}

		void Destroy() { delete this; }
};

class SpiritOfTheVale_Gossip : public Arcemu::Gossip::Script
{
	public:
		void OnHello( Object* pObject, Player* plr )
		{
			Arcemu::Gossip::Menu menu( pObject->GetGUID(), 0 );
			
			if(plr->HasFinishedQuest( 9450 ) == true )
			{
				menu.setTextID( 8826 );
			}
			else
			{
				menu.setTextID( 8827 );
				sQuestMgr.FillQuestMenu( TO< Creature* >( pObject ), plr, menu );
			}
			
			menu.Send( plr );
		}

		void Destroy() { delete this; }
};

void SetupAzuremystIsleGossip( ScriptMgr* mgr )
{
	mgr->register_creature_gossip( 16477, new Proenitus_Gossip );
	mgr->register_creature_gossip( 16514, new BotanistTaerix_Gossip );
	mgr->register_creature_gossip( 17087, new SpiritOfTheVale_Gossip );
}
