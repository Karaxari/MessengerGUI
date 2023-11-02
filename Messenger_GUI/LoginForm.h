#pragma once
#include "DataController.h"
#include <msclr\marshal_cppstd.h>

namespace MessengerGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			dataController = new DataController(false);
			//
			//TODO: добавьте код конструктора
			//
		}

		void deleteDataController() {
			delete dataController;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public: DataController* dataController;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	protected:
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel4;
	private: System::Windows::Forms::RadioButton^ radioButtonClient;
	public: System::Windows::Forms::RadioButton^ radioButtonServer;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ buttonOk;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Button^ buttonRegistration;
	private: System::Windows::Forms::Label^ labelLogin;
	public: System::Windows::Forms::TextBox^ textBoxLogin;
	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::TextBox^ textBoxConfirmPassword;
	private: System::Windows::Forms::Label^ labelConfirmPassword;
	private: System::Windows::Forms::Button^ buttonLogin;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->radioButtonServer = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonClient = (gcnew System::Windows::Forms::RadioButton());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->labelLogin = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBoxConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelConfirmPassword = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->buttonOk = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonRegistration = (gcnew System::Windows::Forms::Button());
			this->buttonLogin = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->flowLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->Controls->Add(this->radioButtonServer);
			this->flowLayoutPanel1->Controls->Add(this->radioButtonClient);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Padding = System::Windows::Forms::Padding(10);
			this->flowLayoutPanel1->Size = System::Drawing::Size(482, 46);
			this->flowLayoutPanel1->TabIndex = 0;
			this->flowLayoutPanel1->UseWaitCursor = true;
			this->flowLayoutPanel1->WrapContents = false;
			// 
			// radioButtonServer
			// 
			this->radioButtonServer->AutoSize = true;
			this->radioButtonServer->Location = System::Drawing::Point(391, 13);
			this->radioButtonServer->Name = L"radioButtonServer";
			this->radioButtonServer->Size = System::Drawing::Size(68, 20);
			this->radioButtonServer->TabIndex = 1;
			this->radioButtonServer->Text = L"Server";
			this->radioButtonServer->UseVisualStyleBackColor = true;
			this->radioButtonServer->UseWaitCursor = true;
			// 
			// radioButtonClient
			// 
			this->radioButtonClient->AutoSize = true;
			this->radioButtonClient->Checked = true;
			this->radioButtonClient->Location = System::Drawing::Point(324, 13);
			this->radioButtonClient->Name = L"radioButtonClient";
			this->radioButtonClient->Size = System::Drawing::Size(61, 20);
			this->radioButtonClient->TabIndex = 0;
			this->radioButtonClient->TabStop = true;
			this->radioButtonClient->Text = L"Client";
			this->radioButtonClient->UseVisualStyleBackColor = true;
			this->radioButtonClient->UseWaitCursor = true;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(200, 100);
			this->flowLayoutPanel2->TabIndex = 0;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->AutoSize = true;
			this->flowLayoutPanel3->Controls->Add(this->panel2);
			this->flowLayoutPanel3->Controls->Add(this->panel1);
			this->flowLayoutPanel3->Controls->Add(this->panel4);
			this->flowLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPanel3->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel3->Location = System::Drawing::Point(0, 46);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Padding = System::Windows::Forms::Padding(10);
			this->flowLayoutPanel3->Size = System::Drawing::Size(482, 188);
			this->flowLayoutPanel3->TabIndex = 0;
			this->flowLayoutPanel3->UseWaitCursor = true;
			this->flowLayoutPanel3->WrapContents = false;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->textBoxLogin);
			this->panel2->Controls->Add(this->labelLogin);
			this->panel2->Location = System::Drawing::Point(13, 13);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(450, 50);
			this->panel2->TabIndex = 0;
			this->panel2->UseWaitCursor = true;
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxLogin->Location = System::Drawing::Point(169, 13);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(250, 27);
			this->textBoxLogin->TabIndex = 0;
			this->textBoxLogin->UseWaitCursor = true;
			// 
			// labelLogin
			// 
			this->labelLogin->AutoSize = true;
			this->labelLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelLogin->Location = System::Drawing::Point(98, 16);
			this->labelLogin->Name = L"labelLogin";
			this->labelLogin->Size = System::Drawing::Size(55, 20);
			this->labelLogin->TabIndex = 1;
			this->labelLogin->Text = L"Login:";
			this->labelLogin->UseWaitCursor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->textBoxPassword);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->labelPassword);
			this->panel1->Location = System::Drawing::Point(13, 69);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(450, 50);
			this->panel1->TabIndex = 1;
			this->panel1->UseWaitCursor = true;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxPassword->Location = System::Drawing::Point(169, 13);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(250, 27);
			this->textBoxPassword->TabIndex = 0;
			this->textBoxPassword->UseSystemPasswordChar = true;
			this->textBoxPassword->UseWaitCursor = true;
			// 
			// panel3
			// 
			this->panel3->Location = System::Drawing::Point(22, 99);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(200, 100);
			this->panel3->TabIndex = 0;
			this->panel3->UseWaitCursor = true;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPassword->Location = System::Drawing::Point(65, 13);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(88, 20);
			this->labelPassword->TabIndex = 1;
			this->labelPassword->Text = L"Password:";
			this->labelPassword->UseWaitCursor = true;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->textBoxConfirmPassword);
			this->panel4->Controls->Add(this->labelConfirmPassword);
			this->panel4->Location = System::Drawing::Point(13, 125);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(450, 50);
			this->panel4->TabIndex = 2;
			this->panel4->UseWaitCursor = true;
			// 
			// textBoxConfirmPassword
			// 
			this->textBoxConfirmPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxConfirmPassword->Location = System::Drawing::Point(169, 10);
			this->textBoxConfirmPassword->Name = L"textBoxConfirmPassword";
			this->textBoxConfirmPassword->Size = System::Drawing::Size(250, 27);
			this->textBoxConfirmPassword->TabIndex = 2;
			this->textBoxConfirmPassword->UseSystemPasswordChar = true;
			this->textBoxConfirmPassword->UseWaitCursor = true;
			this->textBoxConfirmPassword->Visible = false;
			// 
			// labelConfirmPassword
			// 
			this->labelConfirmPassword->AutoSize = true;
			this->labelConfirmPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelConfirmPassword->Location = System::Drawing::Point(3, 13);
			this->labelConfirmPassword->Name = L"labelConfirmPassword";
			this->labelConfirmPassword->Size = System::Drawing::Size(150, 20);
			this->labelConfirmPassword->TabIndex = 4;
			this->labelConfirmPassword->Text = L"Confirm password:";
			this->labelConfirmPassword->UseWaitCursor = true;
			this->labelConfirmPassword->Visible = false;
			// 
			// flowLayoutPanel4
			// 
			this->flowLayoutPanel4->Controls->Add(this->buttonOk);
			this->flowLayoutPanel4->Controls->Add(this->buttonCancel);
			this->flowLayoutPanel4->Controls->Add(this->buttonRegistration);
			this->flowLayoutPanel4->Controls->Add(this->buttonLogin);
			this->flowLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPanel4->Location = System::Drawing::Point(0, 234);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Padding = System::Windows::Forms::Padding(10);
			this->flowLayoutPanel4->Size = System::Drawing::Size(482, 66);
			this->flowLayoutPanel4->TabIndex = 1;
			this->flowLayoutPanel4->UseWaitCursor = true;
			this->flowLayoutPanel4->WrapContents = false;
			// 
			// buttonOk
			// 
			this->buttonOk->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonOk->Location = System::Drawing::Point(13, 13);
			this->buttonOk->Name = L"buttonOk";
			this->buttonOk->Size = System::Drawing::Size(100, 40);
			this->buttonOk->TabIndex = 0;
			this->buttonOk->Text = L"Ok";
			this->buttonOk->UseVisualStyleBackColor = true;
			this->buttonOk->UseWaitCursor = true;
			this->buttonOk->Click += gcnew System::EventHandler(this, &LoginForm::buttonOk_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCancel->Location = System::Drawing::Point(119, 13);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(100, 40);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->UseWaitCursor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &LoginForm::buttonCancel_Click);
			// 
			// buttonRegistration
			// 
			this->buttonRegistration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonRegistration->Location = System::Drawing::Point(225, 13);
			this->buttonRegistration->Name = L"buttonRegistration";
			this->buttonRegistration->Size = System::Drawing::Size(120, 40);
			this->buttonRegistration->TabIndex = 2;
			this->buttonRegistration->Text = L"Register";
			this->buttonRegistration->UseVisualStyleBackColor = true;
			this->buttonRegistration->UseWaitCursor = true;
			this->buttonRegistration->Click += gcnew System::EventHandler(this, &LoginForm::buttonRegistration_Click);
			// 
			// buttonLogin
			// 
			this->buttonLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonLogin->Location = System::Drawing::Point(351, 13);
			this->buttonLogin->Name = L"buttonLogin";
			this->buttonLogin->Size = System::Drawing::Size(120, 40);
			this->buttonLogin->TabIndex = 3;
			this->buttonLogin->Text = L"Login";
			this->buttonLogin->UseVisualStyleBackColor = true;
			this->buttonLogin->UseWaitCursor = true;
			this->buttonLogin->Visible = false;
			this->buttonLogin->Click += gcnew System::EventHandler(this, &LoginForm::buttonLogin_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 303);
			this->Controls->Add(this->flowLayoutPanel4);
			this->Controls->Add(this->flowLayoutPanel3);
			this->Controls->Add(this->flowLayoutPanel1);
			this->MinimumSize = System::Drawing::Size(500, 350);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->UseWaitCursor = true;
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->flowLayoutPanel4->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ClearTextBox() {
		textBoxLogin->Text = "";
		textBoxPassword->Text = "";
		textBoxConfirmPassword->Text = "";
	}
	private: System::Void buttonRegistration_Click(System::Object^ sender, System::EventArgs^ e) {
		buttonRegistration->Visible = false;
		labelConfirmPassword->Visible = true;
		textBoxConfirmPassword->Visible = true;
		buttonLogin->Visible = true;
		ClearTextBox();
	}
	private: System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		buttonLogin->Visible = false;
		labelConfirmPassword->Visible = false;
		textBoxConfirmPassword->Visible = false;
		buttonRegistration->Visible = true;
		ClearTextBox();
	}
	private: System::Void buttonOk_Click(System::Object^ sender, System::EventArgs^ e) {
		//MessengerGUI::MessengerForm messangerForm;
		//Application::Run(% messangerForm);
		/*MessengerForm^ f2 = gcnew MessengerForm();
		f2->Show();*/
		if (textBoxLogin->Text != "" && textBoxPassword->Text != "") {
			std::string login = msclr::interop::marshal_as<std::string>(textBoxLogin->Text->ToString());
			std::string password = msclr::interop::marshal_as<std::string>(textBoxPassword->Text->ToString());

			if (buttonRegistration->Visible) {
				if (radioButtonServer->Checked) {
					if (!dataController->authenticationAdmin(login, password)) {
						ClearTextBox();
						return;
					}
				}
				else {
					if (!dataController->authentication(login, password)) {
						ClearTextBox();
						return;
					}
				}
				dataController->setPersonLogin(login);
				this->Enabled = false;
				this->Close();
			}
			else {
				if (textBoxPassword->Text == textBoxConfirmPassword->Text) {
					MessangerUser user("default", login, password, 0, 0);
					if (radioButtonServer->Checked) {
						user.setRole(1);
					}
					if (dataController->loadUser(user)) {
						dataController->setPersonLogin(login);
						this->Enabled = false;
						this->Close();
					}
					else {
						ClearTextBox();
					}
				}
				else {
					ClearTextBox();
				}
			}
		}
	}
	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
