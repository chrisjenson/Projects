# frozen_string_literal: true

# Filename: prototype1_controller.rb
# Description: This is the controller that is used primarily for navigation throughout the application
# We are ommitting function documentation as each action only routes to a page, nothing more.
class WelcomeController < ApplicationController
  before_action :authenticate_user!, except: [:welcome]

  def studentProfile; end

  def organizationProfile; end

  def celrProfile; end

  def studentLogin; end

  def celrLogin; end

  def organizationLogin; end

  def Events; end

  def Organizations; end

  def studentDisclaimer; end

  def organizationDisclaimer; end
end
