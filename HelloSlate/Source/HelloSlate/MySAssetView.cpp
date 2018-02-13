// Fill out your copyright notice in the Description page of Project Settings.

#include "MySAssetView.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/views/STableRow.h"
#include "Widgets/Colors/SColorBlock.h"
#include "Widgets/SOverlay.h"
#include "Engine.h"

void SMySAssetView::Construct(const FArguments& InArgs)
{
	ChildSlot
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			
		];
}

FReply SMySAssetView::OnDrop(const FGeometry & MyGeometry, const FDragDropEvent & DragDropEvent)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("QuitGameClicked121312312"));
	return FReply::Handled().EndDragDrop();
}


