// Fill out your copyright notice in the Description page of Project Settings.

#include "SChageSunRotation.h"

#define LOCTEXT_NAMESPACE "SChageSunRotation"
void SChageSunRotation::Construct(const FArguments& InArgs)
{
	ChildSlot
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SNew(SColorBlock)
				.Color(FLinearColor::Red)
			]
			+SOverlay::Slot()
			[
				SNew(SBox)
				.HeightOverride(200)
				.WidthOverride(200)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SBox)
						.HeightOverride(30)
						.WidthOverride(200)
						[
							SNew(SOverlay)
							+SOverlay::Slot()
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Fill)
							[
								SNew(SHorizontalBox)
								+SHorizontalBox::Slot()
								.HAlign(HAlign_Center)
								.VAlign(VAlign_Center)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("txt","改变太阳角度"))
								]
							]
							+SOverlay::Slot()
							.HAlign(HAlign_Right)
							.VAlign(VAlign_Fill)
							[
								SNew(SHorizontalBox)
								+SHorizontalBox::Slot()
								.HAlign(HAlign_Right)
								.AutoWidth()
								[
									SNew(SBox)
									.WidthOverride(50)
									.HeightOverride(50)
									[
										SNew(SButton)
										.Text(FText::FromString("X"))
									]
								]
							]
						]
					]
					+SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SBox)
						.HeightOverride(150)
						.WidthOverride(200)
						[
							SNew(SVerticalBox)
							+SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(70)
								[
									SNew(SHorizontalBox)
									+SHorizontalBox::Slot()
									.VAlign(VAlign_Center)
									.HAlign(HAlign_Left)
									[
										SNew(STextBlock)
										.Text(LOCTEXT("12","是否自动"))
									]
									+SHorizontalBox::Slot()
									[
										SAssignNew(SunRotationCheckBox,SCheckBox)
										.Type(ESlateCheckBoxType::CheckBox)
										.OnCheckStateChanged(this,&SChageSunRotation::OnCheckStateChenged)
									]
								]
							]
							+SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(SBox)
								.HeightOverride(80)
								[
									SNew(SHorizontalBox)
									+SHorizontalBox::Slot()
									.VAlign(VAlign_Center)
									.FillWidth(0.75f)
									[
										SAssignNew(SunRotationSlider,SSlider)
										.IsEnabled(false)
										.OnValueChanged(this,&SChageSunRotation::OnValueChanged)
									]
								]
							]
						]
					]
				]
				
			]
		];
}

void SChageSunRotation::OnCheckStateChenged(ECheckBoxState NewState)
{
	bool bIsChecked;
	if (NewState == ECheckBoxState::Checked)
	{
		bIsChecked = true;
		SunRotationSlider->SetEnabled(false);
	}
	else
	{
		bIsChecked = false;
		SunRotationSlider->SetEnabled(true);
	}
	OnCheckBoxStateChanged.ExecuteIfBound(bIsChecked);
}

void SChageSunRotation::OnValueChanged(float NewValue)
{
	OnFloatValueChanged.ExecuteIfBound(NewValue);
}

#undef LOCTEXT_NAMESPACE