//  SuperTux - Climbable area
//  Copyright (C) 2007 Christoph Sommer <christoph.sommer@2007.expires.deltadevelopment.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_TRIGGER_CLIMBABLE_HPP
#define HEADER_SUPERTUX_TRIGGER_CLIMBABLE_HPP

#include "supertux/timer.hpp"
#include "trigger/trigger_base.hpp"

class Color;
class DrawingContext;
class Player;
class ReaderMapping;

class Climbable : public TriggerBase
{
  static Color text_color;
public:
  Climbable(const ReaderMapping& reader);
  Climbable(const Rectf& area);
  ~Climbable();
  std::string get_class() const {
    return "climbable";
  }

  bool has_variable_size() const {
    return true;
  }

  virtual ObjectSettings get_settings();
  virtual void after_editor_set();

  void event(Player& player, EventType type);
  void update(float elapsed_time);
  void draw(DrawingContext& context);

  /**
   * returns true if the player is within bounds of the Climbable
   */
  bool may_climb(Player& player) const;

protected:
  Player* climbed_by; /**< set to player who's currently climbing us, null if nobody is */
  Timer activate_try_timer; /**< try to correct mis-alignment while this timer runs */
  std::string message;

private:
  Vector new_size;

  Climbable(const Climbable&);
  Climbable& operator=(const Climbable&);
};

#endif

/* EOF */
