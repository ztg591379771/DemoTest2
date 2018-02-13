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
 * 自定义的一个DragDrop 操作类
 */
class HELLOSLATE_API FMyDragDropOperation : public FDragDropOperation
{
public:
	DRAG_DROP_OPERATOR_TYPE(FMyDragDropOperation, FDragDropOperation)
	//抓取的数据
	MyAssetData AssetData;
	//创建一个 actor工厂
	//TWeakObjectPtr<class UActorFactory> ActorFactory;

	//创建单独的
    static TSharedRef<FMyDragDropOperation> New(const MyAssetData& InAssetDate);
	////创建数组
	//static TSharedRef<FMyDragDropOperation> New(const TArray<MyAssetData>& InAssetDate, UActorFactory* ActorFactory = NULL);

	//***************************************************
	virtual ~FMyDragDropOperation();

	//原来是protect 现在改成了public
	virtual void Construct() override;

    virtual TSharedPtr<SWidget> GetDefaultDecorator() const override;

	//void Init();
private:
	//缩略图的大小
	int ThumbnailSize;
};
