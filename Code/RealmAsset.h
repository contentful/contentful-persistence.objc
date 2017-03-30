//
//  RealmAsset.h
//  ContentfulSDK
//
//  Created by Boris Bügling on 08/12/14.
//
//

#import <ContentfulDeliveryAPI/CDAPersistedAsset.h>
#import <Realm/RLMObject.h>

@interface RealmAsset : RLMObject <CDAPersistedAsset>


#pragma mark - <CDAPersistedAsset>

/** The description of the Asset. */
@property (nonatomic, nullable) NSString* assetDescription;
/** The title of the Asset. */
@property (nonatomic, nullable) NSString* title;

@end
