# frozen_string_literal: true

#   Class: Organization

class Organization < ApplicationRecord

  validates :name, :email, :phone_no, presence: true
  alias_attribute :approved?, :approved

  belongs_to :user
  has_many :opportunity, dependent: :destroy

  # No dependency action needed
  has_many :favorite_organizations, dependent: :destroy

  belongs_to :tag, optional: true

  def favorited_by
    FavoriteOrganization.where(organization: self).map(&:user)
  end
end
