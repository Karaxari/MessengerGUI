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
	/// —водка дл€ ListPrivateChatsForm
	/// </summary>
	public ref class ListPrivateChatsForm : public System::Windows::Forms::Form
	{
	public:
		ListPrivateChatsForm(void)
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
		~ListPrivateChatsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelSelectPrivateChat;
	public: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPrivateChat;
	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelSelectPrivateChat = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPrivateChat = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->flowLayoutPrivateChat->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelSelectPrivateChat
			// 
			this->labelSelectPrivateChat->AutoSize = true;
			this->labelSelectPrivateChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelSelectPrivateChat->Location = System::Drawing::Point(10, 10);
			this->labelSelectPrivateChat->Margin = System::Windows::Forms::Padding(10, 10, 0, 0);
			this->labelSelectPrivateChat->Name = L"labelSelectPrivateChat";
			this->labelSelectPrivateChat->Size = System::Drawing::Size(68, 20);
			this->labelSelectPrivateChat->TabIndex = 0;
			this->labelSelectPrivateChat->Text = L"Select:";
			this->labelSelectPrivateChat->Click += gcnew System::EventHandler(this, &ListPrivateChatsForm::labelSelectPrivateChat_Click);
			// 
			// flowLayoutPrivateChat
			// 
			this->flowLayoutPrivateChat->AutoScroll = true;
			this->flowLayoutPrivateChat->AutoSize = true;
			this->flowLayoutPrivateChat->Controls->Add(this->labelSelectPrivateChat);
			this->flowLayoutPrivateChat->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPrivateChat->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPrivateChat->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
			this->flowLayoutPrivateChat->MinimumSize = System::Drawing::Size(360, 500);
			this->flowLayoutPrivateChat->Name = L"flowLayoutPrivateChat";
			this->flowLayoutPrivateChat->Size = System::Drawing::Size(362, 500);
			this->flowLayoutPrivateChat->TabIndex = 1;
			this->flowLayoutPrivateChat->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ListPrivateChatsForm::flowLayoutPrivateChat_Paint);
			// 
			// ListPrivateChatsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(362, 473);
			this->Controls->Add(this->flowLayoutPrivateChat);
			this->MinimumSize = System::Drawing::Size(380, 520);
			this->Name = L"ListPrivateChatsForm";
			this->Text = L"ListPrivateChatsForm";
			this->flowLayoutPrivateChat->ResumeLayout(false);
			this->flowLayoutPrivateChat->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void labelSelectPrivateChat_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public: System::Void ShowPrivateChatUsers(System::Object^ sender, System::EventArgs^ e) {
		//std::cout << "Kurva \n";
		Button^ button = (Button^)sender;
		labelSelectPrivateChat->Text = button->Name;
		std::cout << msclr::interop::marshal_as<std::string>(button->Name) << "\n";
		this->Hide();
	}
	private: System::Void flowLayoutPrivateChat_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	};
}
