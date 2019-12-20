# frozen_string_literal: true

# Filename: application_controller.rb
# Description: This is the application controller. From here we perform most of our login and session checking to restrict the access to our pages.

class ApplicationController < ActionController::Base
  protect_from_forgery with: :exception
  before_action :authenticate_user!

  #   Require registered organization accounts to create an organization before they are able
  #   to navigate website.
  #   Pre-Condition: An organization user without an account
  #   Post-Condition: User placed on new organization page
  def org_create_required
    return unless current_user.organization.nil?

    redirect_to new_organization_path, flash: { notice: 'You are required to create an organization profile first' }
  end
end
