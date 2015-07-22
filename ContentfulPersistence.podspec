Pod::Spec.new do |s|
  s.name             = "ContentfulPersistence"
  s.version          = "0.2.0"
  s.summary          = "Simplified persistence for the Contentful iOS SDK."
  s.homepage         = "https://github.com/contentful/contentful-persistence.objc"
  s.license          = 'MIT'
  s.author           = { "Boris Bügling" => "boris@contentful.com" }
  s.source           = { :git => "https://github.com/contentful/contentful-persistence.objc.git",
                         :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/contentful'

  s.requires_arc  = true
  s.frameworks    = 'CoreData'

  s.source_files        = 'Code'
  s.public_header_files = 'Code/*.h'

  s.ios.deployment_target     = '6.0'
  s.ios.source_files          = 'Code/UIKit'
  s.ios.public_header_files   = 'Code/UIKit/*.h'

  s.osx.deployment_target     = '10.8'

  s.dependency 'ContentfulDeliveryAPI', '~> 1.4.7'
end
