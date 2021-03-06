//
//  AINetIndex.h
//  SMG_NothingIsAll
//
//  Created by iMac on 2018/4/20.
//  Copyright © 2018年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>


//MARK:===============================================================
//MARK:                     < 微信息索引 (第一序列) >
//MARK:===============================================================
@class AIPointer,AIKVPointer;
@interface AINetIndex : NSObject

-(AIPointer*) getDataPointerWithData:(NSNumber*)data algsType:(NSString*)algsType dataSource:(NSString*)dataSource;

/**
 *  MARK:--------------------引用序列--------------------
 *  @param indexPointer : value地址
 *  @param target_p : 引用者地址(如:xxNode.pointer)
 */
-(void) setIndexReference:(AIKVPointer*)indexPointer target_p:(AIKVPointer*)target_p difValue:(int)difValue;
-(NSArray*) getIndexReference:(AIKVPointer*)indexPointer limit:(NSInteger)limit;

@end


//MARK:===============================================================
//MARK:                     < 内存DataSortModel (一组index) >
//MARK:===============================================================
@interface AINetIndexModel : NSObject <NSCoding>

@property (strong,nonatomic) NSMutableArray *pointerIds;
@property (strong,nonatomic) NSString *algsType;
@property (strong,nonatomic) NSString *dataSource;

@end
