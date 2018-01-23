/*
 * This file is part of the TREZOR project, https://trezor.io/
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "buttons.h"

struct buttonState button;

void buttonUpdate()
{
	uint16_t state;
	static uint16_t last_state = BTN_PIN_YES | BTN_PIN_NO | BTN_PIN_UP | BTN_PIN_MD | BTN_PIN_DN;

	state = gpio_port_read(BTN_PORT);

	if ((state & BTN_PIN_YES) == 0) {	// Yes button is down
		if ((last_state & BTN_PIN_YES) == 0) {		// last Yes was down
			if (button.YesDown < 2000000000) button.YesDown++;
			button.YesUp = false;
		} else {					// last Yes was up
			button.YesDown = 0;
			button.YesUp = false;
		}
	} else {				// Yes button is up
		if ((last_state & BTN_PIN_YES) == 0) {		// last Yes was down
			button.YesDown = 0;
			button.YesUp = true;
		} else {					// last Yes was up
			button.YesDown = 0;
			button.YesUp = false;
		}
	}

	if ((state & BTN_PIN_NO) == 0) {	// No button is down
		if ((last_state & BTN_PIN_NO) == 0) {		// last No was down
			if (button.NoDown < 2000000000) button.NoDown++;
			button.NoUp = false;
		} else {					// last No was up
			button.NoDown = 0;
			button.NoUp = false;
		}
	} else {				// No button is up
		if ((last_state & BTN_PIN_NO) == 0) {		// last No was down
			button.NoDown = 0;
			button.NoUp = true;
		} else {					// last No was up
			button.NoDown = 0;
			button.NoUp = false;
		}
	}

	if ((state & BTN_PIN_UP) == 0) {	// Up page button is down
		if ((last_state & BTN_PIN_UP) == 0) {		// last Up page was down
			if (button.UpDown < 2000000000) button.UpDown++;
			button.UpUp = false;
		} else {					// last Up page was up
			button.UpDown = 0;
			button.UpUp = false;
		}
	} else {				// Up page button is up
		if ((last_state & BTN_PIN_UP) == 0) {		// last Up page was down
			button.UpDown = 0;
			button.UpUp = true;
		} else {					// last Up page was up
			button.UpDown = 0;
			button.UpUp = false;
		}
	}

	if ((state & BTN_PIN_MD) == 0) {	// Middle button is down
		if ((last_state & BTN_PIN_MD) == 0) {		// last Middle was down
			if (button.MdDown < 2000000000) button.MdDown++;
			button.MdUp = false;
		} else {					// last Middle was up
			button.MdDown = 0;
			button.MdUp = false;
		}
	} else {				// Middle button is up
		if ((last_state & BTN_PIN_MD) == 0) {		// last Middle was down
			button.MdDown = 0;
			button.MdUp = true;
		} else {					// last Middle was up
			button.MdDown = 0;
			button.MdUp = false;
		}
	}

	if ((state & BTN_PIN_DN) == 0) {	// Down button is down
		if ((last_state & BTN_PIN_DN) == 0) {		// last Down was down
			if (button.DnDown < 2000000000) button.DnDown++;
			button.DnUp = false;
		} else {					// last Down was up
			button.DnDown = 0;
			button.DnUp = false;
		}
	} else {				// Down button is up
		if ((last_state & BTN_PIN_DN) == 0) {		// last Down was down
			button.DnDown = 0;
			button.DnUp = true;
		} else {					// last Down was up
			button.DnDown = 0;
			button.DnUp = false;
		}
	}

	last_state = state;
}
