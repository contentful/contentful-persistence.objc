#!/usr/bin/ruby

Pod::Spec.new do |s|
  s.name             = "ContentfulPersistenceObjC"
  s.version          = "1.0.0"
  s.summary          = "Simplified persistence for the Contentful iOS SDK."
  s.homepage         = "https://github.com/contentful/contentful-persistence.objc"
  s.license          = 'MIT'
  s.author           = { "Boris Bügling" => "boris@contentful.com" }
  s.source           = { :git => "https://github.com/contentful/contentful-persistence.objc.git",
                         :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/contentful'

  s.requires_arc  = true

  s.ios.deployment_target = '8.0'
  s.osx.deployment_target = '10.10'

  s.dependency 'ContentfulDeliveryAPI', '~> 2.0.1'

  s.default_subspecs = 'CoreData'

  s.subspec 'CoreData' do |ss|
    ss.frameworks         = 'CoreData'
    ss.source_files       = 'Code/CoreData*.{h,m}'
    ss.ios.source_files   = 'Code/UIKit'
  end

  s.subspec 'Realm' do |ss|
    ss.dependency 'Realm', '~> 2.5.0'

    ss.source_files = 'Code/Realm*.{h,m}'

    ss.ios.deployment_target   = '8.0'
    ss.osx.deployment_target   = '10.10'
  end
end
