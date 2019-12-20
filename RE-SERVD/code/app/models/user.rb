# frozen_string_literal: true

#   Class: User
#
#   Functions:
#     login?(email, password)
#     from_email(email)
#     register(email, password, type)
#     delete_account()
#     set_email(new_email)
#     set_password(new_password)

class User < ApplicationRecord
  VALID_EMAIL_REGEX = /\A[\w+\-.]+@[a-z\d\-.]+\.[a-z]+\z/i.freeze

  # Include default devise modules. Others available are:
  # :confirmable, :lockable, :timeoutable, :trackable and :omniauthable
  devise :database_authenticatable, :registerable,
  :recoverable, :rememberable, :validatable

  before_save { self.email = email.downcase }

  validates :email, presence: true, length: { maximum: 255 },
                    format: { with: VALID_EMAIL_REGEX },
                    uniqueness: { case_sensitive: false }

  validates :password, presence: true, length: { minimum: 6 }
  # has_one :organizations, dependent: :destroy

  # FIXME Broken association
  # Fix assigned to @EthanZeigler
  #
  # Temp through function
  # has_many :favorite_opportunities
  has_one :organization, dependent: :nullify
  belongs_to :tag, optional: true

  has_many :favorite_opportunities, dependent: :destroy
  has_many :favorite_organizations, dependent: :destroy

  def favorite_opportunities
    puts("#############################################\n\n\n\n\n")
    puts("Please do not use favorite_opportunities. It's a temporary bandaid")
    puts("\n\n\n\n\n###########################################")
    self[:favorite_opportunities]
  end

  def favorite_organizations
    puts("#############################################\n\n\n\n\n")
    puts("Please do not use favorite_organizations. It's a temporary bandaid")
    puts("\n\n\n\n\n###########################################")
    self[:favorite_organizations]
  end

  def favorited_opportunities
    FavoriteOpportunity.where(user: self).map(&:opportunity)
  end

  def favorited_organizations
    FavoriteOrganization.where(user: self).map(&:organization)
  end

  def approved_org?
    !organization.nil? && organization.approved?
  end

  def unapproved_org?
    !organization.nil? && !organization.approved?
  end

  def org?
    !organization.nil?
  end
end
