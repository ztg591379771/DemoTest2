// Fill out your copyright notice in the Description page of Project Settings.

#include "MyDragDropOperation.h"
#include "Engine/Level.h"
#include "ActorFactories/ActorFactory.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Colors/SColorBlock.h"
#include "Widgets/Layout/SBox.h"
TSharedRef<FMyDragDropOperation> FMyDragDropOperation::New(const MyAssetData& InAssetDate)
{
	/*TArray<MyAssetData> AssetDataArray;
	AssetDataArray.Add(InAssetDate);
	return New(AssetDataArray, ActorFactory);*/

	TSharedRef<FMyDragDropOperation> Operation = MakeShareable(new FMyDragDropOperation);

	//设置 鼠标的显示
	Operation->MouseCursor = EMouseCursor::GrabHandClosed;
	// 数据
	Operation->AssetData = InAssetDate;

	//
	Operation->ThumbnailSize = 64;

	Operation->Construct();
	return Operation;
}

FMyDragDropOperation::~FMyDragDropOperation()
{

}


void FMyDragDropOperation::Construct()
{
	FDragDropOperation::Construct();
}

TSharedPtr<SWidget> FMyDragDropOperation::GetDefaultDecorator() const
{
	return 
		SNew(SBorder)
		.BorderBackgroundColor(FLinearColor::Red)
		.Content()
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			.HAlign(HAlign_Left)
			.AutoWidth()
			[
				SNew(SBox)
				.WidthOverride(ThumbnailSize)
				.HeightOverride(ThumbnailSize)
				.Padding(FMargin(5))
				[
					SNew(SColorBlock)
					.Color(FLinearColor::Blue)
				]
			]
		];
}
