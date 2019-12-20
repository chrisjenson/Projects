# frozen_string_literal: true

##
# A CEL opportunity registered with an organization
class Opportunity < ApplicationRecord
  alias_attribute :approved?, :approved

  validates :name, :address, :city, :state, :zip_code, :description,
            :frequency, :email, presence: true
  validates :zip_code, numericality: { only_integer: true }

  # FIXME shouldn't be optional long term
  belongs_to :organization, optional: true
  belongs_to :issue_area, optional: true
  belongs_to :tag, optional: true
  has_many :favorite_opportunities, dependent: :destroy

  validates_uniqueness_of :name, scope: :email

  ##
  # True if the given user owns the opportunity
  def owned_by?(user)
    if user.nil?
      false
    else
      organization == user.organization
    end
  end

  def favorited_by
    FavoriteOpportunity.where(opportunity: self).map(&:user)
  end
end
