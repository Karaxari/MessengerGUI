#pragma once
//#include "DataController.h"
//#include <msclr\marshal_cppstd.h>
#include "ListPrivateChatsForm.h"

namespace MessengerGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Сводка для MessengerFormAdmin
	/// </summary>
	public ref class MessengerFormAdmin : public System::Windows::Forms::Form
	{
	public:
		MessengerFormAdmin(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		MessengerFormAdmin(std::string login)
		{
			InitializeComponent();
			dataController = new DataController(login);
			std::cout << login << " Constructor MessengerForm to String! \n";
			ShowGeneralChat();
			InitUserPrivateChat();
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
		~MessengerFormAdmin()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	public: DataController* dataController;
	private: ListPrivateChatsForm^ listPrivateChats = gcnew ListPrivateChatsForm();

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ mainMenuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openAnotherClientToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closeThisClientToolStripMenuItem1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;


	private: System::Windows::Forms::Button^ buttonShowGeneralChat;
	private: System::Windows::Forms::Button^ buttonSwowToPrivate;


	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBoxGeneralChat;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBoxPrivateChat;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mainMenuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openAnotherClientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeThisClientToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->buttonShowGeneralChat = (gcnew System::Windows::Forms::Button());
			this->buttonSwowToPrivate = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBoxGeneralChat = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBoxPrivateChat = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->mainMenuToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(982, 30);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mainMenuToolStripMenuItem
			// 
			this->mainMenuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openAnotherClientToolStripMenuItem,
					this->closeThisClientToolStripMenuItem1
			});
			this->mainMenuToolStripMenuItem->Name = L"mainMenuToolStripMenuItem";
			this->mainMenuToolStripMenuItem->Size = System::Drawing::Size(97, 26);
			this->mainMenuToolStripMenuItem->Text = L"Main menu";
			// 
			// openAnotherClientToolStripMenuItem
			// 
			this->openAnotherClientToolStripMenuItem->Name = L"openAnotherClientToolStripMenuItem";
			this->openAnotherClientToolStripMenuItem->Size = System::Drawing::Size(223, 26);
			this->openAnotherClientToolStripMenuItem->Text = L"Open another client";
			this->openAnotherClientToolStripMenuItem->Click += gcnew System::EventHandler(this, &MessengerFormAdmin::openAnotherClientToolStripMenuItem_Click);
			// 
			// closeThisClientToolStripMenuItem1
			// 
			this->closeThisClientToolStripMenuItem1->Name = L"closeThisClientToolStripMenuItem1";
			this->closeThisClientToolStripMenuItem1->Size = System::Drawing::Size(223, 26);
			this->closeThisClientToolStripMenuItem1->Text = L"Close this client";
			this->closeThisClientToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MessengerFormAdmin::closeThisClientToolStripMenuItem1_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->Controls->Add(this->buttonShowGeneralChat);
			this->flowLayoutPanel1->Controls->Add(this->buttonSwowToPrivate);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 30);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(982, 75);
			this->flowLayoutPanel1->TabIndex = 3;
			// 
			// buttonShowGeneralChat
			// 
			this->buttonShowGeneralChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonShowGeneralChat->Location = System::Drawing::Point(50, 25);
			this->buttonShowGeneralChat->Margin = System::Windows::Forms::Padding(50, 25, 5, 10);
			this->buttonShowGeneralChat->MinimumSize = System::Drawing::Size(150, 40);
			this->buttonShowGeneralChat->Name = L"buttonShowGeneralChat";
			this->buttonShowGeneralChat->Size = System::Drawing::Size(150, 40);
			this->buttonShowGeneralChat->TabIndex = 0;
			this->buttonShowGeneralChat->Text = L"Show to Public";
			this->buttonShowGeneralChat->UseVisualStyleBackColor = true;
			this->buttonShowGeneralChat->Click += gcnew System::EventHandler(this, &MessengerFormAdmin::buttonShowGeneralChat_Click);
			// 
			// buttonSwowToPrivate
			// 
			this->buttonSwowToPrivate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonSwowToPrivate->Location = System::Drawing::Point(210, 25);
			this->buttonSwowToPrivate->Margin = System::Windows::Forms::Padding(5, 25, 5, 10);
			this->buttonSwowToPrivate->MinimumSize = System::Drawing::Size(150, 40);
			this->buttonSwowToPrivate->Name = L"buttonSwowToPrivate";
			this->buttonSwowToPrivate->Size = System::Drawing::Size(150, 40);
			this->buttonSwowToPrivate->TabIndex = 4;
			this->buttonSwowToPrivate->Text = L"Swow to Private";
			this->buttonSwowToPrivate->Click += gcnew System::EventHandler(this, &MessengerFormAdmin::buttonSendPrivate_Click);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->AutoSize = true;
			this->flowLayoutPanel2->Controls->Add(this->panel1);
			this->flowLayoutPanel2->Controls->Add(this->panel2);
			this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPanel2->Location = System::Drawing::Point(0, 105);
			this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(0);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(982, 360);
			this->flowLayoutPanel2->TabIndex = 5;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Window;
			this->panel1->Controls->Add(this->textBoxGeneralChat);
			this->panel1->Location = System::Drawing::Point(30, 20);
			this->panel1->Margin = System::Windows::Forms::Padding(30, 20, 10, 20);
			this->panel1->MinimumSize = System::Drawing::Size(450, 320);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(450, 320);
			this->panel1->TabIndex = 0;
			// 
			// textBoxGeneralChat
			// 
			this->textBoxGeneralChat->AcceptsReturn = true;
			this->textBoxGeneralChat->AcceptsTab = true;
			this->textBoxGeneralChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxGeneralChat->Location = System::Drawing::Point(3, 3);
			this->textBoxGeneralChat->Multiline = true;
			this->textBoxGeneralChat->Name = L"textBoxGeneralChat";
			this->textBoxGeneralChat->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxGeneralChat->Size = System::Drawing::Size(444, 314);
			this->textBoxGeneralChat->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::Window;
			this->panel2->Controls->Add(this->textBoxPrivateChat);
			this->panel2->Location = System::Drawing::Point(500, 20);
			this->panel2->Margin = System::Windows::Forms::Padding(10, 20, 30, 20);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(450, 320);
			this->panel2->TabIndex = 1;
			// 
			// textBoxPrivateChat
			// 
			this->textBoxPrivateChat->AcceptsReturn = true;
			this->textBoxPrivateChat->AcceptsTab = true;
			this->textBoxPrivateChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxPrivateChat->Location = System::Drawing::Point(1, 3);
			this->textBoxPrivateChat->Multiline = true;
			this->textBoxPrivateChat->Name = L"textBoxPrivateChat";
			this->textBoxPrivateChat->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxPrivateChat->Size = System::Drawing::Size(446, 314);
			this->textBoxPrivateChat->TabIndex = 1;
			// 
			// MessengerFormAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 463);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->MinimumSize = System::Drawing::Size(1000, 510);
			this->Name = L"MessengerFormAdmin";
			this->Text = L"MessengerFormAdmin";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void InitUserPrivateChat() {
		std::map<int, PrivateChat> ::iterator it = dataController->_listOfPrivateChat.begin();
		for (int i = 0; it != dataController->_listOfPrivateChat.end(); ++it, ++i) {
			Button^ newButton = gcnew Button();
			newButton->Name = gcnew System::String(std::to_string(it->second.getChatID()).c_str());
			std::string str = it->second.getlogin() + " and " + it->second.getloginCompanion();
			newButton->Text = gcnew System::String(str.c_str());
			newButton->Size = System::Drawing::Size(250, 40);

			newButton->Click += gcnew System::EventHandler(listPrivateChats, &ListPrivateChatsForm::ShowPrivateChatUsers);
			//this.Controls.Add(b);

			//newButton->Click += gcnew System::EventHandler(this, &ShowPrivateChat);
			//newButton->Click += gcnew System::EventHandler(this, &MessengerForm::CloseForm);

			listPrivateChats->flowLayoutPrivateChat->Controls->Add(newButton);
		}
	}

	public:	void ShowGeneralChat() {
		textBoxGeneralChat->Text = "";
		for each (std::string str in dataController->_generalСhat)
		{
			textBoxGeneralChat->Text += gcnew System::String(str.c_str()) + "\r\n";
		}
	}

	public:	void ShowPrivateChat(int chatID) {
		textBoxGeneralChat->Text = "";
		if (dataController->_mapPrivateChatHistory.find(chatID) != dataController->_mapPrivateChatHistory.end()) {
			for (std::string message : dataController->_mapPrivateChatHistory[chatID]) {
				textBoxGeneralChat->Text += gcnew System::String(message.c_str()) + "\r\n";
			}
		}
	}

	private: System::Void СheckingСhatСelection() {
		while (listPrivateChats->flowLayoutPrivateChat->Text == "Select:") {
			//std::cout << "chatID: " << msclr::interop::marshal_as<std::string>(listPrivateChats->flowLayoutPrivateChat->Text) << '\n';
		}
		std::string chatID = msclr::interop::marshal_as<std::string>(listPrivateChats->flowLayoutPrivateChat->Text);
		std::cout << "chatID: " << msclr::interop::marshal_as<std::string>(listPrivateChats->flowLayoutPrivateChat->Text) << '\n';
		//int _chatID = std::stoi(chatID);
		//ShowPrivateChat(_chatID);
		listPrivateChats->flowLayoutPrivateChat->Text = "Select:";
	}

	private: System::Void openAnotherClientToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Enabled = false;
		this->Close();
	}
	private: System::Void closeThisClientToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void buttonSendPrivate_Click(System::Object^ sender, System::EventArgs^ e) {
		listPrivateChats->Show();

		Thread^ thread1 = gcnew Thread(gcnew ThreadStart(this, &MessengerFormAdmin::СheckingСhatСelection));
		thread1->Name = "thread4";
		thread1->Start();
	}
	private: System::Void buttonShowGeneralChat_Click(System::Object^ sender, System::EventArgs^ e) {
		ShowGeneralChat();
	}
	};
}
