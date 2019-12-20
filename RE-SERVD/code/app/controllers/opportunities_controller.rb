# frozen_string_literal: true

#
# Filename: opportunity_controller.rb
# Description: this file is the controller file for all of the opportunities and actions
# associated with the events page.
class OpportunitiesController < ApplicationController
  before_action :set_opportunity, only: %i[favorite show edit update destroy]

  # GET /opportunities
  # GET /opportunities.json

  # Function: favorite
  # Parameters:none
  # Pre-Condition: the user wants to favorite an event
  # Post-Condition: will favorite or unfavorite an event

  def favorite
    type = params[:type]

    if type == 'favorite'
      current_user.favorites << @opportunity
      redirect_to :back, notice: 'You favorited ' + @opportunity.name
    elsif type == 'unfavorite'
      current_user.favorites.delete(@opportunity)
      redirect_to :back, notice: 'Unfavorited ' + @opportunity.name
    else
      redirect_to :back, notice: 'Nothing happened.'
    end
  end

  # Function: index
  # Paramters: none
  # Pre-Condition: the user tries to get to the events page
  # Post-Condition: will display all of the events in the table in the view
  def index
    @opportunities = Opportunity.all
    @opportunities = @opportunities.sort_by &:on_date

    return if current_user.nil? || current_user.tag.nil?

    @recommended_list = Opportunity.where(tag: current_user.tag) # gets all tags that are ligned up
    @recommended_list = @recommended_list.sort_by &:on_date
    @opportunities -= @recommended_list # takes the recommended events out from the
    # event list to avoid duplicates
  end

  # GET /opportunities/1
  # GET /opportunities/1.json
  # Function: show
  # Paramters: none
  # Pre-Condition: the user clicks on a view button for one of the events
  # Post-Condition: user is redirected to a page with all of the selected events information
  def show; end

  # GET /opportunities/new
  # Function: new
  # Parameters: none
  # Pre-Condition: user selects new opportunity
  # Post-Condition: will render a page for the user to create a new opportunity
  def new
    @opportunity = Opportunity.new
  end

  # GET /opportunities/1/edit
  # Function: edit
  # Parameters: none
  # Pre-Condition: user selects the edit button for one of the opportunities in the view
  # Post-Condition: user is taken to the edit page to alter the opportunities information
  def edit; end

  # POST /opportunities
  # POST /opportunities.json
  # Function: create
  # Parameters: none
  # Pre-Condition: the user has filled out the new opportunity form and then selects create event
  # Post-Condition: the new opportunity will be added to the datatable
  def create
    p = opportunity_params
    p[:email] = user_email
    @opportunity = Opportunity.new(p)

    respond_to do |format|
      if @opportunity.save
        format.html { redirect_to @opportunity, notice: 'Opportunity was successfully created.' }
        format.json { render :show, status: :created, location: @opportunity }
      else
        format.html { render :new }
        format.json { render json: @opportunity.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /opportunities/1
  # PATCH/PUT /opportunities/1.json
  # Function: update
  # Parameters: none
  # Pre-Condition: the user has made some changes to the edit view forms and selected the update button
  # Post-Condition: the event in the table will be updated with the new information
  def update
    respond_to do |format|
      if @opportunity.update(opportunity_params)
        format.html { redirect_to @opportunity, notice: 'Opportunity was successfully updated.' }
        format.json { render :show, status: :ok, location: @opportunity }
      else
        format.html { render :edit }
        format.json { render json: @opportunity.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /opportunities/1
  # DELETE /opportunities/1.json
  # Function: destroy
  # Parameters: none
  # Pre-Condition: the user selects on the delete button for the event in the view
  # Post-Condition: the event will be removed from the opportunity table
  def destroy
    @opportunity.destroy
    respond_to do |format|
      format.html { redirect_to opportunities_url, notice: 'Opportunity was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private

  # Use callbacks to share common setup or constraints between actions.
  def set_opportunity
    @opportunity = Opportunity.find(params[:id])
  end

  # Never trust parameters from the scary internet, only allow the white list through.
  def opportunity_params
    params.require(:opportunity).permit(:name, :address, :city, :state, :zip_code, :transportation, :description, :frequency, :email, :on_date, :start_time, :end_time, :issue_area, :tag)
  end
end
