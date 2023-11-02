#pragma once
#include "ConnectionDB.h"
#include <msclr\marshal_cppstd.h>

namespace MessengerGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ UserDelelteForm
	/// </summary>
	public ref class UserDelelteForm : public System::Windows::Forms::Form
	{
	public:
		UserDelelteForm(void)
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
		~UserDelelteForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::FlowLayoutPanel^ flowLayoutUserDelete;
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
			this->flowLayoutUserDelete = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// flowLayoutUserDelete
			// 
			this->flowLayoutUserDelete->AutoScroll = true;
			this->flowLayoutUserDelete->AutoSize = true;
			this->flowLayoutUserDelete->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutUserDelete->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutUserDelete->Location = System::Drawing::Point(0, 0);
			this->flowLayoutUserDelete->MinimumSize = System::Drawing::Size(250, 500);
			this->flowLayoutUserDelete->Name = L"flowLayoutUserDelete";
			this->flowLayoutUserDelete->Size = System::Drawing::Size(411, 500);
			this->flowLayoutUserDelete->TabIndex = 0;
			this->flowLayoutUserDelete->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &UserDelelteForm::flowLayoutUserDelete_Paint);
			// 
			// UserDelelteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(432, 453);
			this->Controls->Add(this->flowLayoutUserDelete);
			this->MinimumSize = System::Drawing::Size(450, 500);
			this->Name = L"UserDelelteForm";
			this->Text = L"UserDelelteForm";
			this->Load += gcnew System::EventHandler(this, &UserDelelteForm::UserDelelteForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: System::Void DeleteUser(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = (Button^)sender;
		ConnectionDB connectionDB;
		std::string login = msclr::interop::marshal_as<std::string>(button->Name);
		std::cout << login << "\n";
		if (connectionDB.deleteUsers(login)) {
			button->Hide();
		}

		this->Hide();
	}
	private: System::Void UserDelelteForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void flowLayoutUserDelete_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	};
}
