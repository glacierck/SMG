//
//  SMGUtils.h
//  SMG_NothingIsAll
//
//  Created by 贾  on 2017/4/19.
//  Copyright © 2017年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>


@class AIPointer,AIKVPointer,AIOutputKVPointer,AIObject,AIArray,AILine,ThinkModel,AIPort;
@interface SMGUtils : NSObject

//MARK:===============================================================
//MARK:                     < 联想AILine点亮区域 >
//MARK:===============================================================

/**
 *  MARK:--------------------层数点亮--------------------
 *  @param layerCount : 节点层数
 *  (0->自己)(1->自己和自己的抽象层)(2->自已,自己的抽象层,抽象层的其它实例,抽象层的抽象层)(>2:以此类推)
 */
+(NSMutableArray*) lightArea_Vertical:(AIObject*)lightModel layerCount:(NSInteger)layerCount;

+(NSMutableArray*) lightArea_Vertical_1:(AIObject*)lightModel;
+(NSMutableArray*) lightArea_Vertical_2:(AIObject*)lightModel;
+(NSMutableArray*) lightArea_Vertical:(AIObject*)lightModel energy:(NSInteger)energy;//使用能量点亮神经网络区域;(依赖AILine的强度)
+(NSMutableArray*) lightArea_Horizontal:(AIObject*)lightModel;
+(NSMutableArray*) lightArea_AILineTypeIsLawWithLightModels:(NSArray*)lightModels;  //横向点亮实例...
+(void) lightArea_AILineTypeIsLaw:(ThinkModel*)thinkModel;//纵向点亮实例...
+(NSMutableArray*) lightArea_LightModels:(NSArray*)lightModels; //区域点亮


//MARK:===============================================================
//MARK:                     < AILine >
//MARK:===============================================================
+(CGFloat) aiLine_GetLightEnergy:(CGFloat)strongValue;//点亮某神经元所需要的能量值;strongValue为0-100,返回为1-0;
+(AILine*) ailine_CreateLine:(NSArray*)aiObjs type:(AILineType)type;//生产神经网络 (aiObjs:神经网络连接的AIObject组)


//MARK:===============================================================
//MARK:                     < AIPointer & PointerId >
//MARK:===============================================================
+(NSInteger) createPointerId:(NSString*)algsType dataSource:(NSString*)dataSource;
+(NSInteger) createPointerId:(BOOL)updateLastId algsType:(NSString*)algsType dataSource:(NSString*)dataSource;
+(NSInteger) getLastNetNodePointerId:(NSString*)algsType dataSource:(NSString*)dataSource;
+(void) setNetNodePointerId:(NSInteger)count algsType:(NSString*)algsType dataSource:(NSString*)dataSource;
+(AIKVPointer*) createPointerForNode:(NSString*)folderName;
+(AIKVPointer*) createPointer:(NSString*)folderName algsType:(NSString*)algsType dataSource:(NSString*)dataSource;
+(AIKVPointer*) createPointerForAbsValue:(NSString*)key;//AbsValue地址,key作为dataSource;
+(AIKVPointer*) createPointerForAbsValue:(NSString*)key pointerId:(NSInteger)pointerId;//AbsValue地址 & key作为dataSource; & 指定pointerId

//Direction的mv分区pointer;(存引用序列)
+(AIKVPointer*) createPointerForDirection:(NSString*)mvAlgsType direction:(MVDirection)direction;

//outputReference的"分区算法标识";(存引用序列)
+(AIOutputKVPointer*) createPointerForOutputReference:(NSString*)algsType dataTo:(NSString*)dataTo;

//生成小脑node指针;
+(AIOutputKVPointer*) createPointerForOutputNode:(NSString*)algsType dataTo:(NSString*)dataTo;

//生成小脑索引指针
+(AIOutputKVPointer*) createPointerForOutputValue:(NSString*)algsType dataTo:(NSString*)dataTo;
+(AIOutputKVPointer*) createPointerForOutputValue:(NSInteger)pointerId algsType:(NSString*)algsType dataTo:(NSString*)dataTo;

@end


//MARK:===============================================================
//MARK:                     < SMGUtils (Compare) >
//MARK:===============================================================
@interface SMGUtils (Compare)

+(BOOL) compareItemA:(id)itemA itemB:(id)itemB;
+(BOOL) compareArrayA:(NSArray*)arrA arrayB:(NSArray*)arrB;
+(BOOL) compareItemA:(id)itemA containsItemB:(id)itemB;
+(NSComparisonResult) comparePointerA:(AIPointer*)pA pointerB:(AIPointer*)pB;
+(NSComparisonResult) compareRefsA_p:(NSArray*)refsA_p refsB_p:(NSArray*)refsB_p;//比较refsA是否比refsB大
+(NSComparisonResult) comparePortA:(AIPort*)pA portB:(AIPort*)pB;
+(NSComparisonResult) compareIntA:(NSInteger)intA intB:(NSInteger)intB;

@end


//MARK:===============================================================
//MARK:                     < @SMGUtils (DB) >
//MARK:===============================================================
@interface SMGUtils (DB)
/**
 *  MARK:--------------------SQL语句之rowId--------------------
 */
+(NSString*) sqlWhere_RowId:(NSInteger)rowid;
+(NSString*) sqlWhere_K:(id)columnName V:(id)value;
+(NSDictionary*) sqlWhereDic_K:(id)columnName V:(id)value;
+(id) searchObjectForPointer:(AIPointer*)pointer fileName:(NSString*)fileName;
+(id) searchObjectForPointer:(AIPointer*)pointer fileName:(NSString*)fileName time:(double)time;//找到后,缓存到redis,time秒;
+(void) insertObject:(NSObject*)obj rootPath:(NSString*)rootPath fileName:(NSString*)fileName;
+(void) insertObject:(NSObject*)obj rootPath:(NSString*)rootPath fileName:(NSString*)fileName time:(double)time;//同时插入到redis,time秒

@end


//MARK:===============================================================
//MARK:                     < MathUtils >
//MARK:===============================================================
@interface MathUtils : NSObject

//数据范围变换
+(CGFloat) getNegativeTen2TenWithOriRange:(UIFloatRange)oriRange oriValue:(CGFloat)oriValue;
+(CGFloat) getZero2TenWithOriRange:(UIFloatRange)oriRange oriValue:(CGFloat)oriValue;
+(CGFloat) getValueWithOriRange:(UIFloatRange)oriRange targetRange:(UIFloatRange)targetRange oriValue:(CGFloat)oriValue;


@end
