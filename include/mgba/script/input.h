/* Copyright (c) 2013-2022 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef M_SCRIPT_INPUT_H
#define M_SCRIPT_INPUT_H

#include <mgba-util/common.h>

#include <mgba/script/context.h>
#include <mgba/script/macros.h>

CXX_GUARD_START

enum mScriptEventType {
	mSCRIPT_EV_TYPE_NONE = 0,
	mSCRIPT_EV_TYPE_KEY,
	mSCRIPT_EV_TYPE_MOUSE_BUTTON,
	mSCRIPT_EV_TYPE_MOUSE_MOVE,
	mSCRIPT_EV_TYPE_MOUSE_WHEEL,
	mSCRIPT_EV_TYPE_GAMEPAD_BUTTON,
	mSCRIPT_EV_TYPE_GAMEPAD_HAT,
	mSCRIPT_EV_TYPE_TRIGGER,
	mSCRIPT_EV_TYPE_MAX
};

enum mScriptInputState {
	mSCRIPT_INPUT_STATE_UP = 0,
	mSCRIPT_INPUT_STATE_DOWN = 1,
	mSCRIPT_INPUT_STATE_HELD = 2,
};

enum mScriptInputDirection {
	mSCRIPT_INPUT_DIR_NONE = 0,

	mSCRIPT_INPUT_DIR_NORTH = 1,
	mSCRIPT_INPUT_DIR_EAST = 2,
	mSCRIPT_INPUT_DIR_SOUTH = 4,
	mSCRIPT_INPUT_DIR_WEST = 8,

	mSCRIPT_INPUT_DIR_UP = mSCRIPT_INPUT_DIR_NORTH,
	mSCRIPT_INPUT_DIR_RIGHT = mSCRIPT_INPUT_DIR_EAST,
	mSCRIPT_INPUT_DIR_DOWN = mSCRIPT_INPUT_DIR_SOUTH,
	mSCRIPT_INPUT_DIR_LEFT = mSCRIPT_INPUT_DIR_WEST,

	mSCRIPT_INPUT_DIR_NORTHEAST = mSCRIPT_INPUT_DIR_NORTH | mSCRIPT_INPUT_DIR_EAST,
	mSCRIPT_INPUT_DIR_NORTHWEST = mSCRIPT_INPUT_DIR_NORTH | mSCRIPT_INPUT_DIR_WEST,
	mSCRIPT_INPUT_DIR_SOUTHEAST = mSCRIPT_INPUT_DIR_SOUTH | mSCRIPT_INPUT_DIR_EAST,
	mSCRIPT_INPUT_DIR_SOUTHWEST = mSCRIPT_INPUT_DIR_SOUTH | mSCRIPT_INPUT_DIR_WEST,
};

enum mScriptKeyModifier {
	mSCRIPT_KMOD_NONE = 0,

	mSCRIPT_KMOD_LSHIFT = 0x1,
	mSCRIPT_KMOD_RSHIFT = 0x2,
	mSCRIPT_KMOD_SHIFT  = 0x3,

	mSCRIPT_KMOD_LCONTROL = 0x4,
	mSCRIPT_KMOD_RCONTROL = 0x8,
	mSCRIPT_KMOD_CONTROL  = 0xC,

	mSCRIPT_KMOD_LALT = 0x10,
	mSCRIPT_KMOD_RALT = 0x20,
	mSCRIPT_KMOD_ALT  = 0x30,

	mSCRIPT_KMOD_LSUPER = 0x40,
	mSCRIPT_KMOD_RSUPER = 0x80,
	mSCRIPT_KMOD_SUPER  = 0xC0,

	mSCRIPT_KMOD_CAPS_LOCK   = 0x100,
	mSCRIPT_KMOD_NUM_LOCK    = 0x200,
	mSCRIPT_KMOD_SCROLL_LOCK = 0x400,
};

#define mSCRIPT_KEYBASE 0x200000

enum mScriptKey {
	mSCRIPT_KEY_NONE = 0,

	mSCRIPT_KEY_BACKSPACE = 0x000008,
	mSCRIPT_KEY_TAB = 0x000009,
	mSCRIPT_KEY_LINE_FEED = 0x00000A,
	mSCRIPT_KEY_ESCAPE = 0x00001B,
	mSCRIPT_KEY_DELETE = 0x00007F,

	mSCRIPT_KEY_F1 = mSCRIPT_KEYBASE | 1,
	mSCRIPT_KEY_F2,
	mSCRIPT_KEY_F3,
	mSCRIPT_KEY_F4,
	mSCRIPT_KEY_F5,
	mSCRIPT_KEY_F6,
	mSCRIPT_KEY_F7,
	mSCRIPT_KEY_F8,
	mSCRIPT_KEY_F9,
	mSCRIPT_KEY_F10,
	mSCRIPT_KEY_F11,
	mSCRIPT_KEY_F12,
	mSCRIPT_KEY_F13,
	mSCRIPT_KEY_F14,
	mSCRIPT_KEY_F15,
	mSCRIPT_KEY_F16,
	mSCRIPT_KEY_F17,
	mSCRIPT_KEY_F18,
	mSCRIPT_KEY_F19,
	mSCRIPT_KEY_F20,
	mSCRIPT_KEY_F21,
	mSCRIPT_KEY_F22,
	mSCRIPT_KEY_F23,
	mSCRIPT_KEY_F24,

	mSCRIPT_KEY_UP = mSCRIPT_KEYBASE | 0x20,
	mSCRIPT_KEY_RIGHT,
	mSCRIPT_KEY_DOWN,
	mSCRIPT_KEY_LEFT,
	mSCRIPT_KEY_PAGE_UP,
	mSCRIPT_KEY_PAGE_DOWN,
	mSCRIPT_KEY_HOME,
	mSCRIPT_KEY_END,
	mSCRIPT_KEY_INSERT,
	mSCRIPT_KEY_BREAK,
	mSCRIPT_KEY_CLEAR,
	mSCRIPT_KEY_PRNTSCR,
	mSCRIPT_KEY_SYSRQ,
	mSCRIPT_KEY_MENU,

	mSCRIPT_KEY_LSHIFT = mSCRIPT_KEYBASE | 0x30,
	mSCRIPT_KEY_RSHIFT,
	mSCRIPT_KEY_SHIFT,
	mSCRIPT_KEY_LCONTROL,
	mSCRIPT_KEY_RCONTROL,
	mSCRIPT_KEY_CONTROL,
	mSCRIPT_KEY_LALT,
	mSCRIPT_KEY_RALT,
	mSCRIPT_KEY_ALT,
	mSCRIPT_KEY_LSUPER,
	mSCRIPT_KEY_RSUPER,
	mSCRIPT_KEY_SUPER,
	mSCRIPT_KEY_CAPS_LOCK,
	mSCRIPT_KEY_NUM_LOCK,
	mSCRIPT_KEY_SCROLL_LOCK,
};

struct mScriptEvent {
	int32_t type;
	int32_t reserved;
	uint64_t seq;
};

struct mScriptKeyEvent {
	struct mScriptEvent d;
	uint8_t state;
	uint8_t reserved;
	uint16_t modifiers;
	uint32_t key;
};

struct mScriptMouseButtonEvent {
	struct mScriptEvent d;
	uint8_t state;
	uint8_t mouse;
	uint8_t button;
};

struct mScriptMouseMoveEvent {
	struct mScriptEvent d;
	bool relative;
	uint8_t mouse;
	int32_t x;
	int32_t y;
};

struct mScriptMouseWheelEvent {
	struct mScriptEvent d;
	uint8_t mouse;
	int32_t x;
	int32_t y;
};

struct mScriptGamepadButtonEvent {
	struct mScriptEvent d;
	uint8_t state;
	uint8_t pad;
	uint16_t button;
};

struct mScriptGamepadHatEvent {
	struct mScriptEvent d;
	uint8_t pad;
	uint8_t hat;
	uint8_t direction;
};

struct mScriptTriggerEvent {
	struct mScriptEvent d;
	uint8_t trigger;
	bool state;
};

mSCRIPT_DECLARE_STRUCT(mScriptEvent);
mSCRIPT_DECLARE_STRUCT(mScriptKeyEvent);
mSCRIPT_DECLARE_STRUCT(mScriptMouseButtonEvent);
mSCRIPT_DECLARE_STRUCT(mScriptMouseMoveEvent);
mSCRIPT_DECLARE_STRUCT(mScriptMouseWheelEvent);
mSCRIPT_DECLARE_STRUCT(mScriptGamepadButtonEvent);
mSCRIPT_DECLARE_STRUCT(mScriptGamepadHatEvent);
mSCRIPT_DECLARE_STRUCT(mScriptSensorEvent);
mSCRIPT_DECLARE_STRUCT(mScriptTriggerEvent);

void mScriptContextAttachInput(struct mScriptContext* context);

void mScriptContextFireEvent(struct mScriptContext*, struct mScriptEvent*);

CXX_GUARD_END

#endif
