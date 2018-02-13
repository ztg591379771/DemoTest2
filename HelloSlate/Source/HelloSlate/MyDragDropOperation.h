// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Input/DragAndDrop.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Text/STextBlock.h"
#include "MyAssetData.h"
#include "EditorStyleSet.h"

/**
 * �Զ����һ��DragDrop ������
 */
class HELLOSLATE_API FMyDragDropOperation : public FDragDropOperation
{
public:
	DRAG_DROP_OPERATOR_TYPE(FMyDragDropOperation, FDragDropOperation)
	//ץȡ������
	MyAssetData AssetData;
	//����һ�� actor����
	//TWeakObjectPtr<class UActorFactory> ActorFactory;

	//����������
    static TSharedRef<FMyDragDropOperation> New(const MyAssetData& InAssetDate);
	////��������
	//static TSharedRef<FMyDragDropOperation> New(const TArray<MyAssetData>& InAssetDate, UActorFactory* ActorFactory = NULL);

	//***************************************************
	virtual ~FMyDragDropOperation();

	//ԭ����protect ���ڸĳ���public
	virtual void Construct() override;

    virtual TSharedPtr<SWidget> GetDefaultDecorator() const override;

	//void Init();
private:
	//����ͼ�Ĵ�С
	int ThumbnailSize;
};
