#pragma once
//#include "LoginForm.h"
//#include "DataController.h"
#include "UserListForm.h"
//#include "LoginForm.h"
//#include <msclr\marshal_cppstd.h>;

namespace MessengerGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Сводка для MessengerForm
	/// </summary>
	public ref class MessengerForm : public System::Windows::Forms::Form
	{
	public:
		MessengerForm(void)
		{
			InitializeComponent();
			dataController = new DataController();
			std::cout << "Constructor MessengerForm! \n";
			ShowGeneralChat();
			InitUserListForm();
			//
			//TODO: добавьте код конструктора
			//
		}

		MessengerForm(std::string login)
		{
			InitializeComponent();
			dataController = new DataController(login);

			Thread^ thread1 = gcnew Thread(gcnew ThreadStart(this, &MessengerForm::LoaderDataController));
			thread1->Name = "thread1";
			thread1->Start();

			std::cout << login << " Constructor MessengerForm to String! \n";
			ShowGeneralChat();
			//InitUserListForm();
			//
			//TODO: добавьте код конструктора
			//
		}

		void deleteDataController() {
			delete dataController;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MessengerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:


	public: DataController* dataController;
	private: UserListForm^ userListForm = gcnew UserListForm();

	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::TextBox^ textBoxMessage;
	private: System::Windows::Forms::Button^ buttonSendToAll;
	private: System::Windows::Forms::Button^ buttonSendPrivate;
	protected:

	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ labelMessage;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;


	private: System::Windows::Forms::ToolStripMenuItem^ openAnotherClientToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ closeThisClientToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ opToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mainMenuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openAnotherClientToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closeThisClientToolStripMenuItem1;
	private: System::Windows::Forms::TextBox^ textBoxPrivateChat;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ openAnotherLoginToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closeThisLoginToolStripMenuItem;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
	private: System::Windows::Forms::Button^ buttonSendToAll_2;
	private: System::Windows::Forms::Button^ buttonSendPrivate_2;
	private: System::Windows::Forms::TextBox^ textBoxMessage_2;



	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ textBoxGeneralChat_2;
	private: System::Windows::Forms::TextBox^ textBoxPrivateChat_2;
	private: System::Windows::Forms::Label^ label1;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openAnotherLoginToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeThisLoginToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxMessage_2 = (gcnew System::Windows::Forms::TextBox());
			this->buttonSendToAll_2 = (gcnew System::Windows::Forms::Button());
			this->buttonSendPrivate_2 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBoxGeneralChat_2 = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBoxPrivateChat_2 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip2->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			this->flowLayoutPanel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem1 });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(982, 30);
			this->menuStrip2->TabIndex = 0;
			this->menuStrip2->Text = L"menuStrip2";
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openAnotherLoginToolStripMenuItem,
					this->closeThisLoginToolStripMenuItem
			});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(93, 24);
			this->toolStripMenuItem1->Text = L"MainMenu";
			this->openAnotherLoginToolStripMenuItem->Name = L"openAnotherLoginToolStripMenuItem";
			this->openAnotherLoginToolStripMenuItem->Size = System::Drawing::Size(223, 26);
			this->openAnotherLoginToolStripMenuItem->Text = L"Open another client";
			this->openAnotherLoginToolStripMenuItem->Click += gcnew System::EventHandler(this, &MessengerForm::openAnotherLoginToolStripMenuItem_Click);
			this->closeThisLoginToolStripMenuItem->Name = L"closeThisLoginToolStripMenuItem";
			this->closeThisLoginToolStripMenuItem->Size = System::Drawing::Size(223, 26);
			this->closeThisLoginToolStripMenuItem->Text = L"Close this client";
			this->closeThisLoginToolStripMenuItem->Click += gcnew System::EventHandler(this, &MessengerForm::closeThisLoginToolStripMenuItem_Click);
			this->flowLayoutPanel3->AutoSize = true;
			this->flowLayoutPanel3->Controls->Add(this->label1);
			this->flowLayoutPanel3->Controls->Add(this->textBoxMessage_2);
			this->flowLayoutPanel3->Controls->Add(this->buttonSendToAll_2);
			this->flowLayoutPanel3->Controls->Add(this->buttonSendPrivate_2);
			this->flowLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPanel3->Location = System::Drawing::Point(0, 30);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(982, 75);
			this->flowLayoutPanel3->TabIndex = 1;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(5, 35);
			this->label1->Margin = System::Windows::Forms::Padding(5, 35, 0, 10);
			this->label1->MinimumSize = System::Drawing::Size(121, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Your message:";
			this->textBoxMessage_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxMessage_2->Location = System::Drawing::Point(131, 30);
			this->textBoxMessage_2->Margin = System::Windows::Forms::Padding(5, 30, 5, 10);
			this->textBoxMessage_2->MinimumSize = System::Drawing::Size(300, 30);
			this->textBoxMessage_2->Name = L"textBoxMessage_2";
			this->textBoxMessage_2->Size = System::Drawing::Size(300, 30);
			this->textBoxMessage_2->TabIndex = 4;
			this->buttonSendToAll_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSendToAll_2->Location = System::Drawing::Point(441, 25);
			this->buttonSendToAll_2->Margin = System::Windows::Forms::Padding(5, 25, 5, 10);
			this->buttonSendToAll_2->MinimumSize = System::Drawing::Size(140, 40);
			this->buttonSendToAll_2->Name = L"buttonSendToAll_2";
			this->buttonSendToAll_2->Size = System::Drawing::Size(140, 40);
			this->buttonSendToAll_2->TabIndex = 0;
			this->buttonSendToAll_2->Text = L"Send to all";
			this->buttonSendToAll_2->UseVisualStyleBackColor = true;
			this->buttonSendToAll_2->Click += gcnew System::EventHandler(this, &MessengerForm::buttonSendToAll_2_Click);
			this->buttonSendPrivate_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSendPrivate_2->Location = System::Drawing::Point(591, 25);
			this->buttonSendPrivate_2->Margin = System::Windows::Forms::Padding(5, 25, 5, 10);
			this->buttonSendPrivate_2->MinimumSize = System::Drawing::Size(140, 40);
			this->buttonSendPrivate_2->Name = L"buttonSendPrivate_2";
			this->buttonSendPrivate_2->Size = System::Drawing::Size(140, 40);
			this->buttonSendPrivate_2->TabIndex = 1;
			this->buttonSendPrivate_2->Text = L"Send to Privat\r\n";
			this->buttonSendPrivate_2->UseVisualStyleBackColor = true;
			this->buttonSendPrivate_2->Click += gcnew System::EventHandler(this, &MessengerForm::buttonSendPrivate_2_Click);
			this->flowLayoutPanel4->AutoSize = true;
			this->flowLayoutPanel4->Controls->Add(this->panel3);
			this->flowLayoutPanel4->Controls->Add(this->panel4);
			this->flowLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPanel4->Location = System::Drawing::Point(0, 105);
			this->flowLayoutPanel4->Margin = System::Windows::Forms::Padding(0);
			this->flowLayoutPanel4->MinimumSize = System::Drawing::Size(982, 360);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Size = System::Drawing::Size(982, 360);
			this->flowLayoutPanel4->TabIndex = 2;
			this->panel3->Controls->Add(this->textBoxGeneralChat_2);
			this->panel3->Location = System::Drawing::Point(30, 20);
			this->panel3->Margin = System::Windows::Forms::Padding(30, 20, 10, 20);
			this->panel3->MinimumSize = System::Drawing::Size(450, 320);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(450, 320);
			this->panel3->TabIndex = 0;
			this->textBoxGeneralChat_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxGeneralChat_2->Location = System::Drawing::Point(0, 3);
			this->textBoxGeneralChat_2->Multiline = true;
			this->textBoxGeneralChat_2->Name = L"textBoxGeneralChat_2";
			this->textBoxGeneralChat_2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxGeneralChat_2->Size = System::Drawing::Size(447, 317);
			this->textBoxGeneralChat_2->TabIndex = 0;
			this->panel4->Controls->Add(this->textBoxPrivateChat_2);
			this->panel4->Location = System::Drawing::Point(500, 20);
			this->panel4->Margin = System::Windows::Forms::Padding(10, 20, 30, 20);
			this->panel4->MinimumSize = System::Drawing::Size(450, 320);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(450, 320);
			this->panel4->TabIndex = 1;
			this->textBoxPrivateChat_2->Location = System::Drawing::Point(3, 3);
			this->textBoxPrivateChat_2->Multiline = true;
			this->textBoxPrivateChat_2->Name = L"textBoxPrivateChat_2";
			this->textBoxPrivateChat_2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxPrivateChat_2->Size = System::Drawing::Size(444, 314);
			this->textBoxPrivateChat_2->TabIndex = 0;
			this->ClientSize = System::Drawing::Size(982, 463);
			this->Controls->Add(this->flowLayoutPanel4);
			this->Controls->Add(this->flowLayoutPanel3);
			this->Controls->Add(this->menuStrip2);
			this->MainMenuStrip = this->menuStrip2;
			this->MinimumSize = System::Drawing::Size(1000, 510);
			this->Name = L"MessengerForm";
			this->Text = L"MessengerForm";
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			this->flowLayoutPanel4->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:	void ShowGeneralChat() {
		for each (std::string str in dataController->_generalСhat)
		{
			textBoxGeneralChat_2->Text += gcnew System::String(str.c_str()) + "\r\n";
		}
	}

	private: void InitUserListForm() {
		std::list<std::string> userList = dataController->getUsersList();
		for (std::string user : userList) {
			Button^ newButton = gcnew Button();
			newButton->Name = gcnew System::String(user.c_str());
			newButton->Text = gcnew System::String(user.c_str());
			newButton->Size = System::Drawing::Size(100, 40);

			newButton->Click += gcnew System::EventHandler(userListForm, &UserListForm::ShowPrivateChatUsers);
			//this.Controls.Add(b);

			//newButton->Click += gcnew System::EventHandler(this, &ShowPrivateChat);
			//newButton->Click += gcnew System::EventHandler(this, &MessengerForm::CloseForm);

			userListForm->flowLayoutUserListPanel->Controls->Add(newButton);  //.Controls.Add(newButton);
			std::cout << user << '\n';
		}
	}

		  //public: delegate void ShowPrivateChat(System::String login);
		  //public: void ShowPrivateChat(std::string login) {

		  //}
	private: System::Void СheckingСhatСelection() {
		while (userListForm->labelSelectUser->Text == "Select:") {}
		std::string login = msclr::interop::marshal_as<std::string>(userListForm->labelSelectUser->Text);
		userListForm->labelSelectUser->Text = "Select:";
		textBoxPrivateChat_2->Text = "";
		ShowPrivateChat(login);
	}

	private: void LoaderDataController() {
		//dataController->dataLoader();
		 InitUserListForm();
		//for each (std::string str in dataController->_generalСhat)
		//{
		//	textBoxPrivateChat_2->Text += gcnew System::String(str.c_str()) + "\r\n";
		//}
	}

	private: void ShowPrivateChat(std::string loginCompanion) {
		int chatId = dataController->getPrivateChatID(dataController->getPersonLogin(), loginCompanion);

		if (chatId != 0) {
			if (dataController->_mapPrivateChatHistory.find(chatId) != dataController->_mapPrivateChatHistory.end()) {
				for (std::string message : dataController->_mapPrivateChatHistory[chatId]) {
					textBoxPrivateChat_2->Text += gcnew System::String(message.c_str()) + "\r\n";
				}
			}
			if (textBoxMessage_2->Text != "") {
				std::string message = msclr::interop::marshal_as<std::string>(textBoxMessage_2->Text);
				std::string _messange = dataController->setPrivateChatMessage(chatId, loginCompanion, message);
				if(_messange != "")
					textBoxPrivateChat_2->Text += gcnew System::String(_messange.c_str()) + "\r\n";
			}
		}
		else {
			if (textBoxMessage_2->Text != "") {
				std::string message = msclr::interop::marshal_as<std::string>(textBoxMessage_2->Text);
				std::string _messange = dataController->createPrivateChatMessage(loginCompanion, message);
				if (_messange != "")
					textBoxPrivateChat_2->Text += gcnew System::String(_messange.c_str()) + "\r\n";
			}
		}
	}

	private: System::Void MessengerForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBoxPrivateChat_2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void buttonSendToAll_2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBoxMessage_2->Text != "") {
			std::string currentTime = getCurrentTimeDB();
			std::string messageText = msclr::interop::marshal_as<std::string>(textBoxMessage_2->Text);
			std::string message = dataController->getPersonLogin() + ":" + currentTime + ":" + messageText;
			textBoxGeneralChat_2->Text += gcnew System::String(message.c_str()) + "\r\n";

			dataController->setMessage(dataController->getPersonLogin(), currentTime, messageText);
			textBoxMessage_2->Text = "";
		}
	}
	private: System::Void buttonSendPrivate_2_Click(System::Object^ sender, System::EventArgs^ e) {
		//userListForm->flowLayoutUserListPanel->Padding = System::Windows::Forms::Padding(10, 10, 0, 0);
		//UserListForm^ userListForm = gcnew UserListForm();
		userListForm->Show();

		Thread^ thread1 = gcnew Thread(gcnew ThreadStart(this, &MessengerForm::СheckingСhatСelection));
		thread1->Name = "thread1";
		thread1->Start();
	}
	private: System::Void openAnotherLoginToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Enabled = false;
		this->Close();
	}
	private: System::Void closeThisLoginToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
