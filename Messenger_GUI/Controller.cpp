#include "Controller.h"
//#include <iostream>
#include "DataController.h"
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	setlocale(LC_ALL, "rus");
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	//FlagControl* flagControl = new FlagControl();
	//while (flagControl->getFlagAuten())
	//{
	bool cyclicFlag = false;
	while (!cyclicFlag) {
		MessengerGUI::LoginForm loginForm;
		Application::Run(% loginForm);
		//std::string unmanaged = msclr::interop::marshal_as<std::string>(lofinForm.CausesValidation);
		//std::cout << loginForm.Enabled << '\n';
		//std::cout << loginForm.radioButtonServer->Checked << '\n';
		//std::string _login = msclr::interop::marshal_as<std::string>(loginForm.textBoxLogin->Text);
		//std::cout << _login << '\n';
		//std::cout << loginForm.dataController->getPersonLogin() << '\n';
		///*	std::string unmanaged = msclr::interop::marshal_as<std::string>(loginForm.GetChildAtPoint(System::Drawing::Point(391, 13))->Name->ToString());
		//	std::cout << unmanaged << '\n';*/
		//	//}
		//std::string _login = msclr::interop::marshal_as<std::string>(loginForm.textBoxLogin->Text);

		if (!loginForm.Enabled) {
			if (loginForm.radioButtonServer->Checked) {
				MessengerGUI::MessengerFormAdmin messangerFormAdmin(loginForm.dataController->getPersonLogin());
				Application::Run(% messangerFormAdmin);
				cyclicFlag = messangerFormAdmin.Enabled;
				messangerFormAdmin.deleteDataController();
			}
			else {
				MessengerGUI::MessengerForm messangerForm(loginForm.dataController->getPersonLogin());
				Application::Run(% messangerForm);
				cyclicFlag = messangerForm.Enabled;
				messangerForm.deleteDataController();
			}
		}
		loginForm.deleteDataController();
	}
}