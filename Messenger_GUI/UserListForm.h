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
	/// —водка дл€ UserListForm
	/// </summary>
	public ref class UserListForm : public System::Windows::Forms::Form
	{
	public:
		UserListForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~UserListForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::FlowLayoutPanel^ flowLayoutUserListPanel;
	public: System::Windows::Forms::Label^ labelSelectUser;
	public:

	public:

	public:
	protected:

	protected:

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
			this->flowLayoutUserListPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->labelSelectUser = (gcnew System::Windows::Forms::Label());
			this->flowLayoutUserListPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// flowLayoutUserListPanel
			// 
			this->flowLayoutUserListPanel->AutoScroll = true;
			this->flowLayoutUserListPanel->AutoSize = true;
			this->flowLayoutUserListPanel->Controls->Add(this->labelSelectUser);
			this->flowLayoutUserListPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutUserListPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutUserListPanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->flowLayoutUserListPanel->Location = System::Drawing::Point(0, 0);
			this->flowLayoutUserListPanel->Margin = System::Windows::Forms::Padding(0);
			this->flowLayoutUserListPanel->Name = L"flowLayoutUserListPanel";
			this->flowLayoutUserListPanel->Size = System::Drawing::Size(342, 453);
			this->flowLayoutUserListPanel->TabIndex = 0;
			this->flowLayoutUserListPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &UserListForm::flowLayoutUserListPanel_Paint);
			// 
			// labelSelectUser
			// 
			this->labelSelectUser->AutoSize = true;
			this->labelSelectUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelSelectUser->Location = System::Drawing::Point(10, 10);
			this->labelSelectUser->Margin = System::Windows::Forms::Padding(10, 10, 0, 0);
			this->labelSelectUser->Name = L"labelSelectUser";
			this->labelSelectUser->Size = System::Drawing::Size(68, 20);
			this->labelSelectUser->TabIndex = 0;
			this->labelSelectUser->Text = L"Select:";
			// 
			// UserListForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(342, 453);
			this->Controls->Add(this->flowLayoutUserListPanel);
			this->MinimumSize = System::Drawing::Size(360, 500);
			this->Name = L"UserListForm";
			this->Text = L"UserListForm";
			this->flowLayoutUserListPanel->ResumeLayout(false);
			this->flowLayoutUserListPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void flowLayoutUserListPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	public: System::Void ShowPrivateChatUsers(System::Object^ sender, System::EventArgs^ e) {
		//std::cout << "Kurva \n";
		Button^ button = (Button^)sender;
		labelSelectUser->Text = button->Text;
		std::cout << msclr::interop::marshal_as<std::string>(button->Text) << "\n";
		this->Hide();
	}
	};
}
