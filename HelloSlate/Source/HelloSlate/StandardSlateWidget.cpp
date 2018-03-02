// Fill out your copyright notice in the Description page of Project Settings.

#include "StandardSlateWidget.h"
#include "SlateOptMacros.h"
#include "SlateBasics.h"
#include "MyClass.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

// ++ This is needed in order to use the localization macro LOCTEXT
#define LOCTEXT_NAMESPACE "SStandardSlateWidget"

void SStandardSlateWidget::Construct(const FArguments& InArgs)
{
	// ++ Asign the argument to our local variable
	// name will be _OwnerHUDArg instead of OwnerHUDArg, see comments about SLATE_ARGUMENT before
	OwnerHUD = InArgs._OwnerHUDArg;
	
	UMyClass::Get()->SaveUserName(FString("ssss"));
	// ++ Add all this Slate code
	// If the code below doesn't look like C++ to you it's because it (sort-of) isn't,
	// Slate makes extensive use of the C++ Prerocessor(macros) and operator overloading,
	// Epic is trying to make our lives easier, look-up the macro/operator definitions to see why.
	 UserName = UMyClass::Get()->GetUserName();
	 Password = UMyClass::Get()->GetPassword();
	ChildSlot
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.VAlign(VAlign_Center)
			[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				[
					// Inside lies a text block with these settings
					SNew(STextBlock)
					.Font(FSlateFontInfo("Veranda", 24))
					// localized text to be translated with a generic name HelloSlateText
					.Text(LOCTEXT("username","�û��� :"))
				]
				+SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Font(FSlateFontInfo("Veranda", 24))
					// localized text to be translated with a generic name HelloSlateText
					.Text(FText::FromString(UserName))
				]
				
			]
			+SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				[
					// Inside lies a text block with these settings
					SNew(STextBlock)
					.Font(FSlateFontInfo("Veranda", 24))
					// localized text to be translated with a generic name HelloSlateText
					.Text(LOCTEXT("password","��  �� :"))
				]
				
				+SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Font(FSlateFontInfo("Veranda", 24))
					// localized text to be translated with a generic name HelloSlateText
					.Text(FText::FromString(Password))
				]
			]
			
		]
		];

}



// ++ We need to undefine this namespace after we finish creating the Slate widget
#undef LOCTEXT_NAMESPACE

END_SLATE_FUNCTION_BUILD_OPTIMIZATION