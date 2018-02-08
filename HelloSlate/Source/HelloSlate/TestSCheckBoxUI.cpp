// Fill out your copyright notice in the Description page of Project Settings.

#include "TestSCheckBoxUI.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SScrollBar.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Views/SListView.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Colors/SColorBlock.h"
#include "Widgets/Input/SCheckBox.h"
#include "SlateOptMacros.h"
void STestSCheckBoxUI::Construct(const FArguments& InArgs)
{


	TArray<MyInfo> Categories;
	Categories.Add(MyInfo(FText::FromString("1"), FName("Apple1")));
	Categories.Add(MyInfo(FText::FromString("2"), FName("Apple2")));
	Categories.Add(MyInfo(FText::FromString("3"), FName("Apple3")));
	Categories.Add(MyInfo(FText::FromString("4"), FName("Apple4")));
	ActiveTabName = Categories.GetData()->UniqueHandle;
	bNeedsUpdate = true;
	MapInfo.Add(FName("Apple1"), MyInfo(FText::FromString("1"), FName("Apple1")));
	MapInfo.Add(FName("Apple2"), MyInfo(FText::FromString("2"), FName("Apple2")));
	MapInfo.Add(FName("Apple3"), MyInfo(FText::FromString("3"), FName("Apple3")));
	MapInfo.Add(FName("Apple4"), MyInfo(FText::FromString("4"), FName("Apple4")));
	TSharedRef<SVerticalBox> MyTaps = SNew(SVerticalBox);

	for (const MyInfo info : Categories)
	{
		MyTaps->AddSlot()
			.AutoHeight()
			[
				CreateMyInfoTap(info)
			];
	}

	ChildSlot
		[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.Padding(0)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				MyTaps
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SBorder)
				.Padding(3)
				[
					SNew(SOverlay)
					+ SOverlay::Slot()
					[
						SNew(SBox)
						.HeightOverride(600)
						.WidthOverride(300)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							[
								SNew(STextBlock)
								.Text(this, &STestSCheckBoxUI::GetDynamicText)
							]
						]
					]
				]
			]
		]
		];
}

TSharedRef< SWidget > STestSCheckBoxUI::CreateMyInfoTap(const MyInfo& Info)
{
	return SNew(SCheckBox)
		.Type(ESlateCheckBoxType::ToggleButton)
		.OnCheckStateChanged(this, &STestSCheckBoxUI::OnPlacementTabChanged, Info.UniqueHandle)
		.IsChecked(this, &STestSCheckBoxUI::GetPlacementTabCheckedState, Info.UniqueHandle)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(SSpacer)
			.Size(FVector2D(1, 30))
		]
	+ SOverlay::Slot()
		.Padding(FMargin(6, 0, 15, 0))
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(Info.DisPlayName)
		]
	+ SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Left)
		[
			SNew(SImage)
			.Image(this, &STestSCheckBoxUI::PlacementGroupBorderImage, Info.UniqueHandle)
		]


		];
}

void STestSCheckBoxUI::OnPlacementTabChanged(ECheckBoxState NewState, FName CategoryName)
{
	if (NewState == ECheckBoxState::Checked)
	{
		ActiveTabName = CategoryName;
		//添加什么东西
		//IPlacementModeModule::Get().RegenerateItemsForCategory(ActiveTabName);

		bNeedsUpdate = true;
	}
}

ECheckBoxState STestSCheckBoxUI::GetPlacementTabCheckedState(FName CategoryName) const
{
	return ActiveTabName == CategoryName ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

const FSlateBrush* STestSCheckBoxUI::PlacementGroupBorderImage(FName CategoryName) const
{
	if (CategoryName == ActiveTabName)
	{
		return nullptr; //当选中时一种图片，暂时先不妨图片
	}
	else
	{
		return nullptr;
	}
}

FText STestSCheckBoxUI::GetDynamicText() const
{
	const MyInfo* Category = MapInfo.Find(ActiveTabName);

	if (Category)
	{
		return Category->DisPlayName;
	}
	else
	{
		return FText::FromString("查询内容不存在！");
	}

}
