//
//  AINetDirectionReference.h
//  SMG_NothingIsAll
//
//  Created by iMac on 2018/7/11.
//  Copyright © 2018年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  MARK:--------------------CMV方向索引--------------------
 *  1. 用于mvNode的唯一抽象;(+或-的
 *  2. 每种类型的mindValue仅有一个+,一个-;所以无需引用序列;
 *  3. 每种类型的mindValue仅有一个+和-值,所以无需索引序列;
 *  4. 在本类中,分别存储每个mv类型的正负两个序列,将所有类型的mv的+和-的节点地址,以有序的方式依次存入;
 *  5. mv的索引序列与引用序列都在本类中;因为direction没有值,只有方向;
 *  6. 每个mv区的引用序列,以(按引用数排序)(如吃饭,比吃苹果引用数高很多)
 */
@interface AINetDirectionReference : NSObject

/**
 *  MARK:--------------------给cmvNode建索引--------------------
 *  @param cmvNode_p : 指cmvNode或absCMVNode的节点地址;
 *  @param mvAlgsType : 引用序列的分区标识
 */
-(void) setNodePointerToDirectionReference:(AIKVPointer*)cmvNode_p mvAlgsType:(NSString*)mvAlgsType direction:(MVDirection)direction difStrong:(NSInteger)difStrong;


/**
 *  MARK:--------------------查找direction引用的节点的node_p地址--------------------
 *  @param limit : 最多少个
 *  @param mvAlgsType : 分区标识(mv类型)
 *  @param direction : mv变化方向
 */
-(NSArray*) getNodePointersFromDirectionReference:(NSString*)mvAlgsType direction:(MVDirection)direction limit:(NSInteger)limit;

@end
