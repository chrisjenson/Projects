# frozen_string_literal: true

# Class: Tag
#
# Functions:
# create_tag(tag_name)
# delete_tag()
#
class Tag < ApplicationRecord
  validates_uniqueness_of :name

  alias_attribute :approved?, :approved

  has_many :user, dependent: :nullify
  has_many :favorite_opportunity, dependent: :nullify
  has_many :organization, dependent: :nullify
  has_many :idea, dependent: :nullify
end
