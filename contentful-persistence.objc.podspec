Pod::Spec.new do |s|
  s.name             = "contentful-persistence.objc"
  s.version          = "0.1.0"
  s.summary          = "Simplified persistence for the Contentful iOS SDK."
  s.homepage         = "https://github.com/contentful/contentful-persistence.objc"
  s.license          = 'MIT'
  s.author           = { "Boris Bügling" => "boris@contentful.com" }
  s.source           = { :git => "https://github.com/contentful/contentful-persistence.objc.git",
                         :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/contentfulapp'

  s.platform     = :ios, '6.0'
  s.requires_arc = true

  s.source_files = 'Code'
  s.public_header_files = 'Code/*.h'

end
