#pragma once
#include "LoginForm.h"
#include "MessengerForm.h"
#include "MessengerFormAdmin.h"

public class FlagControl
{
public:
	static bool flagAuten;
	FlagControl();
	static void setFlagAuten(bool flag) { flagAuten = flag; }
	static bool getFlagAuten() { return flagAuten; }
};

namespace ControllerGUI {
	bool flag = false;

	void setFlagTrue() { flag = true; }
}
