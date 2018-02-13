// Fill out your copyright notice in the Description page of Project Settings.

#include "CanDragWidget.h"
#include "MyDragDropOperation.h"
#include "MyAssetData.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Colors/SColorBlock.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine.h"

void SCanDragWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
		[
			SNew(SBox)
			.WidthOverride(150)
			.HeightOverride(150)
			[
				SNew(SColorBlock)
				.Color(FLinearColor::Red)

			]

		];

	
}

FReply SCanDragWidget::OnDragDetected(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	MyAssetData MyData;
	MyData.i = 1;
	if (MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("QuitGameClicked"));
		return FReply::Handled().BeginDragDrop(FMyDragDropOperation::New(MyData));
	}
	else
	{
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

