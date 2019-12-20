# frozen_string_literal: true

# Idea Project
# This gives the user and orgs the ability to create ideas to:
# help the community and allow for collaboration
#
# organizations_controller.rb

# Filename: organizations_controller.rb
# Description: this file is the controller class for the organization view page and all associated
# interactions
class OrganizationsController < ApplicationController
  before_action :set_organization, only: %i[show edit update destroy]

  # GET /organizations
  # GET /organizations.json
  # Function: index
  # Parameters: none
  # Pre-Condition: the user selects the organizations view from the toolbar
  # Post-Condition: a table of all organizations will be displayed to the user
  def index
    @organizations = Organization.all
    @organizations = @organizations.sort_by &:name
  end

  # GET /organizations/1
  # GET /organizations/1.json
  # Function: show
  # Parameters: none
  # Pre-Condition: the user selects view for some organization in the view
  # Post-Condition: a page with all of the organizataions information will be displayed
  def show; end

  # Function: dashboard
  # Parameters: none
  # Pre-Condition: the user selects the organization/user dashboard view from the toolbar
  # Post-Condition: the user will be displayed all of the
  def dashboard
    if current_user.org?
      @organizations = Organization.where('email = ?', user_email)
      @organizations = @organizations.sort_by &:name

      @opportunities = Opportunity.where('email = ?', user_email)
      @opportunities = @opportunities.sort_by &:on_date
    elsif false # TODO ADMIN
      @organizations = Organization.all.sort_by &:name

      @opportunities = Opportunity.all.sort_by &:on_date
    else # normal user
      @organizations = Organization.where(approved: true).sort_by(&:name)
      @opportunities = Opportunity.all
      @favorites = current_user.favorited_opportunities
      @favorites = @favorites.sort_by(&:created_at).reverse
    end
  end

  # GET /organizations/new
  # Function: new
  # Parameters: none
  # Pre-Condition: the user attempts to create a new organization account
  # Post-Condition: the form for the organization information will be displayed to be filled out
  def new
    @organization = Organization.new
  end

  # GET /organizations/1/edit
  # Function: edit
  # Parameters: none
  # Pre-Condition: the user selects the edit button next to their organization
  # Post-Condition: the user will be displayed the edit page to make changes
  def edit; end

  # POST /organizations
  # POST /organizations.json
  # Function: create
  # Parameters: none
  # Pre-Condition: the user must have filled out the org form and then click the create button
  # Post-Condition: the organizations information will be  in the table to the new information
  def create
    p = organization_params
    p[:email] = user_email
    @organization = Organization.new(p)
    @organization.approved = FALSE
    respond_to do |format|
      if @organization.save
        format.html { redirect_to @organization, notice: 'Organization was successfully created.' }
        format.json { render :show, status: :created, location: @organization }
      else
        format.html { render :new }
        format.json { render json: @organization.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /organizations/1
  # PATCH/PUT /organizations/1.json
  # Function: update
  # Parameters: none
  # Pre-Condition: the user must have made some changes to the edit form and hit the update button
  # Post-Condition: the organizations information will be updated in the table
  def update
    respond_to do |format|
      if @organization.update(organization_params)
        format.html { redirect_to @organization, notice: 'Organization was successfully updated.' }
        format.json { render :show, status: :ok, location: @organization }
      else
        format.html { render :edit }
        format.json { render json: @organization.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /organizations/1
  # DELETE /organizations/1.json
  # Function: destroy
  # Parameters: none
  # Post-Condition: the organization will be removed from the table
  def destroy
    @organization.destroy
    respond_to do |format|
      format.html { redirect_to organizations_url, notice: 'Organization was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private

  # Use callbacks to share common setup or constraints between actions.
  def set_organization
    @organization = Organization.find(params[:id])
  end

  # Never trust parameters from the scary internet, only allow the white list through.
  def organization_params
    params.require(:organization).permit(:email, :name, :phone_no, :address, :city, :state, :zip_code, :description, :approved, :issue_area)
  end
end
